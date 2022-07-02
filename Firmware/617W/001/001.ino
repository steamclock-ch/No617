#include "IN17.h"

#include <FS.h>
#include <SPIFFSIniFile.h>
#include <ESP8266httpUpdate.h>

#include <DNSServer.h>
DNSServer dnsServer;

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

#include <TimeLib.h>
#include <Timezone.h>    // https://github.com/JChristensen/Timezone
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <U8x8lib.h>
#include <Wire.h>

#include <ESP8266HTTPClient.h>

#include "params.h"

// NTP Servers:
static const char ntpServerName[] = "ch.pool.ntp.org";
bool upFlag = false;

Params params;
bool actAsPortal;

U8X8_SSD1306_128X32_UNIVISION_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   


enum _epage {homePage,dstPage,timezonePage,timeformatPage,zeroblankingPage,tubeintensityPage,timeserverPage,wifiPage,systemPage};
_epage currentPage;

WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

AsyncWebServer server(80);

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

time_t prevDisplay = 0; // when the digital clock was displayed

int WiFiNetworkCount;
IN17 nixie;
const int _pwm = 13;


//*********************************************************
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(_pwm, OUTPUT); // pwm
  analogWrite(_pwm, 200); 
  Wire.begin(5,4); /// Mark1 
  
  Serial.begin(115200);
  delay(250);
  Serial.println("");
  Serial.println(ESP.getResetReason());
  Serial.println("");
  time_t ct = compileTime();
  char buffer[30];
  printf(buffer,"\n STARTING VERSION %02d.%02d.%02d @ %02d:%02d:%02d \n",  day(ct), month(ct), year(ct), hour(ct), minute(ct), second(ct));

  setupSPIFFS();
  
  nixie.InitExtenders();

  nixie.DisplayRaw("123321");
     
  setupOLED();
  LogSPIFFS_Log(String(buffer));
  params.displayParams();
 
  nixie.DisplayRaw("120021"); 
  LogSPIFFS_Log("Setup Wifi\n");
  actAsPortal=setupWiFi();  
  nixie.DisplayRaw("100001");
  
  nixie.DisplayRaw("000000");
  setupWebServer(actAsPortal);

  nixie.DisplayRaw("123321");
  setupTime();
 
  nixie.TubesTest();
  LogSPIFFS_Log("End of Setup\n");
}


// -------------------------------------------------- 
void adaptTubesLuminosity(bool& showSeconds)
{
  static int currentPWM = 200;
  int targetPWM;
  int adc;

  switch (params.luminosityMode) {
  case 9: analogWrite(_pwm, 200);showSeconds = true ;  break; // max light
  case 8: analogWrite(_pwm, 300);showSeconds = true ; break;
  case 7: analogWrite(_pwm, 400);showSeconds = true ; break;
  case 6: analogWrite(_pwm, 500);showSeconds = true ; break;
  case 5: analogWrite(_pwm, 600);showSeconds = true ; break;
  case 4: analogWrite(_pwm, 700);showSeconds = true ; break;
  case 3: analogWrite(_pwm, 800);showSeconds = true ; break;
  case 2: analogWrite(_pwm, 900);showSeconds = false; break;
  case 1: analogWrite(_pwm, 950);showSeconds = false; break; // min light
  case 0:
    adc = analogRead(A0);
    
    targetPWM = 1024 - adc;
    if (targetPWM < 200) targetPWM = 200;
    if (targetPWM > 1005) targetPWM = 1005;

    if (currentPWM > targetPWM + 15) currentPWM = currentPWM - 15;
    if (currentPWM < targetPWM - 15) currentPWM = currentPWM + 15;

    if (currentPWM < 200) currentPWM = 200;
    if (currentPWM > 1005) currentPWM = 1005;

    analogWrite(_pwm, currentPWM);

    showSeconds = (currentPWM < 900);

    if (currentPWM!=targetPWM)
      Serial.printf("currentPWM vs Target PWM %d - %d \n ",currentPWM, targetPWM);
    break;

  default: analogWrite(_pwm, 200);
  }
      
}

//*********************************************************
void digitalClockDisplay()
{  
  time_t local,UTC;
  bool showH,showSeconds,canShowSeconds;
  char time[9];
  
  adaptTubesLuminosity(canShowSeconds);  
   
  UTC = now();
 // Serial.printf("UTC  %02d:%02d:%02d ",  hour(), minute(), second());
     
  local = getTime(params.DSTZone, params.timeOffsetIndex , UTC);
//  Serial.printf("LOCAL %02d:%02d:%02d ",  hour(), minute(), second());
  
  
  sprintf( time, " %02d:%02d:%02d ",  hour(local), minute(local), second(local));

  if (params.timeFormat==h12){
    if  (hour(local)>12) {
      tmElements_t tm;
      tm.Hour   = hour(local)-12;
      tm.Minute = minute(local);
      tm.Second = second(local);
      local = makeTime(tm);
    }
  }
   
  if (params.isZeroBlanked) 
    showH =  hour(local)>=10;
  else 
    showH = true;

  if (params.secondsBlankingAllowed) 
    showSeconds =  canShowSeconds;
  else 
    showSeconds = true;
    
  nixie.DisplayTime(local,showSeconds,showH);
  u8x8.drawString(0,2,time);
  

 

/*
  if (params.DSTZone>0)
  {
    Serial.print(params.getDSTName(params.DSTZone));
  }
  
  if (params.timeOffsetIndex>0)
  {
    Serial.print(params.getTimezoneName(params.timeOffsetIndex));
  }


  Serial.print(" Local time is ");
  Serial.print(time);
  Serial.print(" ");
  
  Serial.print(day(local));
  Serial.print(".");
  Serial.print(month(local));
  Serial.print(".");
  Serial.print(year(local));
  Serial.println(); 
  */


}

//*********************************************************
void loop()
{
  static char syncWindow =0;
  static int syncInterval=10;
  dnsServer.processNextRequest();  
  if (!actAsPortal)
  //{
  //  
    
 // }
  //else
  {
    if (now() != prevDisplay){
      if (timeStatus() != timeNotSet){
          prevDisplay = now();
          digitalClockDisplay();
      } else {
        u8x8.drawString(0,3,"Time not set 10s");//C-L
        
        if (syncInterval!=10){  
          setSyncInterval(10);//60s*60m*6h 
          syncInterval=10;
          Serial.println("Sync interval set to 10s");
        }
      }
    
      if (timeStatus()==timeNeedsSync){
        u8x8.drawString(0,3,"Sync needed (10s)");//C-L
        syncWindow ++;
        if (syncWindow > 10){
          if(syncInterval!=10){
            Serial.println("Sync interval set to 10s");
            setSyncInterval(10);
            syncInterval=10;
          }
        }    
      }
      
      if (timeStatus()==timeSet)    {
        u8x8.drawString(0,3,"Sync done (6h)");//C-L
        syncWindow=0;
        if(syncInterval!=21600){
          setSyncInterval(21600);//60s*60m*6h 
          syncInterval=21600;
          Serial.println("Sync interval set to 6h");
        }
        
      }
    }
  }

  if (upFlag){
    delay(1000);
    upFlag = false;
    setupOTA(ClockType);  
  }
 

}
