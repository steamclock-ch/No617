
String TI_processor(const String& var){

       if (var == "CLASS_TI0"){ return (params.luminosityMode==0)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI1"){ return (params.luminosityMode==1)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI2"){ return (params.luminosityMode==2)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI3"){ return (params.luminosityMode==3)?"class=\"disabled\"":"";}  
  else if (var == "CLASS_TI4"){ return (params.luminosityMode==4)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI5"){ return (params.luminosityMode==5)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI6"){ return (params.luminosityMode==6)?"class=\"disabled\"":"";}  
  else if (var == "CLASS_TI7"){ return (params.luminosityMode==7)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI8"){ return (params.luminosityMode==8)?"class=\"disabled\"":"";} 
  else if (var == "CLASS_TI9"){ return (params.luminosityMode==9)?"class=\"disabled\"":"";}  
  else if (var == "CLASS_BO0"){ return (!params.secondsBlankingAllowed) ?"class=\"disabled\"" :"";} 
  else if (var == "CLASS_BO1"){ return (params.secondsBlankingAllowed)?"class=\"disabled\"":"";} 
  else if (var == "BO_VALUE" ){ return (params.secondsBlankingAllowed)?"Currently seconds are hidden on low brightness":"Currently seconds are displayed on low brightness";}
  else if (var == "TI_VALUE") { return params.getTubeIntensityLabel(params.luminosityMode);} 
  else if (var == "CLOCKTYPE"){ return String(ClockType);}  
  else if (var == "CLOCKNAME"){ return params.clockName ;}; 
  
  return processor(var);
}

//***************************************************************************************************************************************************************************  
String TZ_processor(const String& var){
  
  if(var == "CLASS_TZ00"){
    return (params.timeOffsetIndex==0)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ01"){
    return (params.timeOffsetIndex==1)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ02"){
    return (params.timeOffsetIndex==2)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ03"){
    return (params.timeOffsetIndex==3)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ04"){
    return (params.timeOffsetIndex==4)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ05"){
    return (params.timeOffsetIndex==5)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ06"){
    return (params.timeOffsetIndex==6)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ07"){
    return (params.timeOffsetIndex==7)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ08"){
    return (params.timeOffsetIndex==8)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ09"){
    return (params.timeOffsetIndex==9)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ10"){
    return (params.timeOffsetIndex==10)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ11"){
    return (params.timeOffsetIndex==11)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ12"){
    return (params.timeOffsetIndex==12)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ13"){
    return (params.timeOffsetIndex==13)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ14"){
    return (params.timeOffsetIndex==14)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ15"){
    return (params.timeOffsetIndex==15)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ16"){
    return (params.timeOffsetIndex==16)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ17"){
    return (params.timeOffsetIndex==17)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ18"){
    return (params.timeOffsetIndex==18)?"class=\"disabled\"":"";
 } else if (var == "CLASS_TZ19"){
    return (params.timeOffsetIndex==19)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ20"){
    return (params.timeOffsetIndex==20)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ21"){
    return (params.timeOffsetIndex==21)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ22"){
    return (params.timeOffsetIndex==22)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ23"){
    return (params.timeOffsetIndex==23)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ24"){
    return (params.timeOffsetIndex==24)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ25"){
    return (params.timeOffsetIndex==25)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ26"){
    return (params.timeOffsetIndex==26)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ27"){
    return (params.timeOffsetIndex==27)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ28"){
    return (params.timeOffsetIndex==28)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ29"){
    return (params.timeOffsetIndex==29)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ30"){
    return (params.timeOffsetIndex==30)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ31"){
    return (params.timeOffsetIndex==31)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ32"){
    return (params.timeOffsetIndex==32)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ33"){
    return (params.timeOffsetIndex==33)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ34"){
    return (params.timeOffsetIndex==34)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ35"){
    return (params.timeOffsetIndex==35)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ36"){
    return (params.timeOffsetIndex==36)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ37"){
    return (params.timeOffsetIndex==37)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ38"){
    return (params.timeOffsetIndex==38)?"class=\"disabled\"":"";
  } else if (var == "CLASS_TZ39"){
    return (params.timeOffsetIndex==39)?"class=\"disabled\"":"";
  } else if (var == "TZ_CURRENTZONE"){
    return params.getTimezoneName(params.timeOffsetIndex);
  }
  
  return processor(var);
  
}

//***************************************************************************************************************************************************************************
String DST_processor(const String& var){
  if(var == "CLASS_DST_NONE"){
    return (params.DSTZone==0)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_EUGMT"){
    return (params.DSTZone==1)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_EUWET"){
   return (params.DSTZone==2)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_EUCET"){
   return (params.DSTZone==3)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_EUEET"){
   return (params.DSTZone==4)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_USPT"){
   return (params.DSTZone==5)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_USMT"){
   return (params.DSTZone==6)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_USCT"){
   return (params.DSTZone==7)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_AUET"){
   return (params.DSTZone==8)?"class=\"disabled\"":"";
  }
  else if (var == "CLASS_DST_USET"){
   return (params.DSTZone==9)?"class=\"disabled\"":"";
  }
  else if (var == "DST_CURRENTZONE"){
    return params.getDSTName(params.DSTZone);
  }    
  else if (var == "CLOCKTYPE"){ 
    return String(ClockType); 
  }  
  else if (var == "CLOCKNAME"){ 
    return params.clockName; }; 
  

  return processor(var);
}


String log_processor(const String& var){
  if(var == "SPIFFSLogs"){
    return LogSPIFFS_Read();  
  }
  
  return processor(var);
}

String firmware (){
  time_t ct = compileTime();
   String retVal;
   retVal = "No 612W " + String(day(ct))+"."+ String(month(ct))+"."+ String(year(ct))+" @ "+ String(hour(ct))+":"+ String(minute(ct))+":"+ String(second(ct)); 
   return retVal;
}

//***************************************************************************************************************************************************************************
String processor(const String& var){
  if(var == "CLASS_HOME")                { return (currentPage==homePage)?"class=\"active\"":"";}  
  else if (var == "CLASS_DST")           { return (currentPage==dstPage)?"class=\"active\"":"";  }  
  else if (var == "CLASS_TIMEZONE")      { return (currentPage==timezonePage)?"class=\"active\"":"";}
  else if (var == "CLASS_TIMEFORMAT")    { return (currentPage==timeformatPage)?"class=\"active\"":"";}
  else if (var == "CLASS_ZEROBLANKING")  { return (currentPage==zeroblankingPage)?"class=\"active\"":""; }  
  else if (var == "CLASS_TUBEINTENSITY") { return (currentPage==tubeintensityPage)?"class=\"active\"":"";  }  
  else if (var == "CLASS_TIMESERVER")    { return (currentPage==timeserverPage)?"class=\"active\"":"";  }
  else if (var == "CLASS_WIFI")          { return (currentPage==wifiPage)?"class=\"active\"":"";  }
  else if (var == "CLASS_SYSTEM")        { return (currentPage==systemPage)?"class=\"active\"":"";  }
  else if (var == "CLASS_ZEROBLANKED")   { return (params.isZeroBlanked)?"success":"default"; }
  else if (var == "CLASS_ZERONOTBLANKED"){ return (!params.isZeroBlanked)?"success":"default"; }
  
  else if (var == "CLASS_12H")           { return (params.timeFormat==h12)?"success":"default"; }
  else if (var == "CLASS_24H")           { return (params.timeFormat==h24)?"success":"default"; }
  else if (var == "TF")                  { return (params.timeFormat==h12)?"12h (AM/PM)":"24h";}
  
  else if (var == "FW")                  { return firmware();} 
  else if (var == "DST")                 { return params.getDSTName(params.DSTZone);}
  
  else if (var == "TZ")                  { return params.getTimezoneName(params.timeOffsetIndex);}
  else if (var == "ZB")                  { return (params.isZeroBlanked)?" not ":" ";}
  else if (var == "TI")                  { return params.getTubeIntensityLabel(params.luminosityMode);} 
  else if (var == "BS")                  { return (params.secondsBlankingAllowed)?" hidden ":" displayed";}
  else if (var == "TS")                  { return params.timeServer;}
  else if (var == "WI")                  { return params.WiFiSSID;}
  
  else if (var == "CLOCKTYPE")           { return String(ClockType); }  
  else if (var == "CLOCKNAME")           { return params.clockName; }; 

  return ("P?");
}

//***************************************************************************************************************************************************************************
String WIFIList(){  
  String retVal = "";
   
  for (int i = 0; i < WiFiNetworkCount ; i++)
  {
    String bgColor = (WiFi.SSID(i)== params.WiFiSSID) ? "Green":"Snow";
    
    // Serial.printf("%d: %s, Ch:%d (%ddBm) %s\n", i+1, WiFi.SSID(i).c_str(), WiFi.channel(i), WiFi.RSSI(i), WiFi.encryptionType(i) == ENC_TYPE_NONE ? "open" : "");
    retVal = retVal + "<div class=\"form-group row\">";
    retVal = retVal + "<div class=\"col-sm-4\" <p class=\"text-secondary\"> "+ WiFi.SSID(i).c_str()+" ("+WiFi.RSSI(i)+"dBm) </p></div>";
    retVal = retVal + "<div class=\"col-sm-4\" \"> <input type=\"password\"  id=\""+i+"\" name=\""+i+"\" class=\"form-control\" placeholder=\"Password\" value=\"\">    </div>";  
    retVal = retVal + "</div>";   
  }
  
  Serial.println();
   
  return retVal;
}

//***************************************************************************************************************************************************************************
String WIFI_processor(const String& var){
  if(var == "CLASS_WIFILIST"){ return WIFIList(); };

  return processor(var);
}

//***************************************************************************************************************************************************************************
  String PORTAL_processor(const String& var){
  if(var == "CLASS_WIFILIST"){ return WIFIList(); };
}

//***************************************************************************************************************************************************************************
void onRequest(AsyncWebServerRequest *request){
  //Handle Unknown Request
  request->send(200, "text/plain", "not found");
}

//************************************************************************************************************************************************************
void setupWebServer(boolean asPortal)
{
  
  
  if (asPortal==true){  
    Serial.println("Setup Captive POrtal");
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
    {
      Serial.println("on / GET as portal ");
      currentPage = homePage;
      request->send(SPIFFS, "/portal.html", String(), false, PORTAL_processor);  
    });
  } 
  else  {
    Serial.println("Setup WebServer");
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
      {
        Serial.println("on / GET not portal");
        currentPage = homePage;
        request->send(SPIFFS, "/index.html", String(), false, processor);  
      });
 }

   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage = homePage;
    Serial.println("on / GET");
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });  

  server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    currentPage = homePage;
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });  

  server.on("/bootstrap.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/bootstrap.css", "text/css");
  });  

  server.on("/Time_zones_of_Europe.png", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/Time_zones_of_Europe.png", "text/css");
  });

  server.on("/bootstrap.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/bootstrap.js", "text/css");
  }); 

  server.on("/jquery.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/jquery.js", "text/css");
  }); 

  server.on("/dst.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage = dstPage;
    Serial.println("\dst.html");
    int dstZone=0;
    int paramsNr = request->params();
    for(int i=0;i<paramsNr;i++){
      AsyncWebParameter* p = request->getParam(i);
      if  (p->name()=="dstName"){
        if (p->value()=="NONE"){           dstZone=0;
        } else if (p->value()=="EUGMT"){   dstZone=1;
        } else if (p->value()=="EUWET"){   dstZone=2;
        } else if (p->value()=="EUCET"){   dstZone=3;
        } else if (p->value()=="EUEET"){   dstZone=4;
        } else if (p->value()=="USPT"){    dstZone=5;
        } else if (p->value()=="USMT"){    dstZone=6;
        } else if (p->value()=="USCT"){    dstZone=7;
        } else if (p->value()=="AUET"){    dstZone=8;
        } else if (p->value()=="USET"){    dstZone=9;
        }
        params.setDSTZone(dstZone);
      }
    }
    
    
    request->send(SPIFFS, "/dst.html", String(), false, DST_processor);
  });

  server.on("/timezone.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage=timezonePage;

    int paramsNr = request->params();
    for(int i=0;i<paramsNr;i++){
      AsyncWebParameter* p = request->getParam(i);
      if  (p->name()=="tz"){
        String stval=p->value();
        int timeZone = stval.toInt();
       
        if ((timeZone>=0)&&(timeZone<40)){
          params.setTimeOffsetIndex(timeZone); 
        } else {
          params.setTimeOffsetIndex(0); 
        }
      }
    }
    
    request->send(SPIFFS, "/timezone.html", String(), false, TZ_processor);
  });

  server.on("/timeformat.html", HTTP_GET, [](AsyncWebServerRequest *request){
    currentPage=timeformatPage;
    int paramsNr = request->params();
    for(int i=0;i<paramsNr;i++){
      AsyncWebParameter* p = request->getParam(i);
      if  (p->name()=="format")
      {
        params.setTimeFormat((p->value()=="12")?h12:h24);
      }
    }
    request->send(SPIFFS, "/timeformat.html", String(), false, processor);
  });

  server.on("/zeroblanking.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage=zeroblankingPage;

    int paramsNr = request->params();
    for(int i=0;i<paramsNr;i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      if  (p->name()=="blank")
      {
        params.setZeroBlanking(p->value()=="Y");
      }
    }
   
    request->send(SPIFFS, "/zeroblanking.html", String(), false, processor);
  });

  server.on("/tubeintensity.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage=tubeintensityPage;
    int paramsNr = request->params();
    for(int i=0;i<paramsNr;i++){
      AsyncWebParameter* p = request->getParam(i);
      
      if  (p->name()=="intensity")
      {
        String stval=p->value();
        int tuint = stval.toInt();
        if ((tuint>=0)&&(tuint<10))
        {
          params.setLuminosityMode(tuint); 
        } else
          params.setLuminosityMode(0);
        }
                      
        if  (p->name()=="bol")
        {
          params.setSecondsBlankingAllowed(p->value() =="1");
        }
    }
       
    request->send(SPIFFS, "/tubeintensity.html", String(), false, TI_processor);
  });

  server.on("/timezonemap.jpg", HTTP_GET, [](AsyncWebServerRequest *request){
    currentPage=timezonePage;
    request->send(SPIFFS, "/timezonemap.jpg", "image/png");
  });

  server.on("/wifi.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    currentPage=wifiPage;
    request->send(SPIFFS, "/wifi.html", String(), false, WIFI_processor);
  });
  
  server.on("/wifi.html", HTTP_POST, [](AsyncWebServerRequest *request){
    currentPage=wifiPage;

    int params = request->params();
    for(int i=0;i<params;i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      if(p->isPost()){
        Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
        if (p->value() != "")
        {
          Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
          int ssid = p->name().toInt();
          
          Serial.printf("setting up SSID:Pwd to %s:%s \n",WiFi.SSID(ssid).c_str(), p->value().c_str());
          Params params;
          params.saveWiFiSSID(WiFi.SSID(ssid).c_str());
          params.saveWiFiPSK(p->value().c_str());
          params.setWiFiCredentialsValidity(true);
          delay(1000);
          Serial.println("\n\nReset\n");
          
          ESP.reset();  
  
        }   
      }
    }
    
    request->send(SPIFFS, "/wifi.html", String(), false, WIFI_processor);
  });


  server.on("/system.html", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("\n/system.html");
    currentPage=systemPage;
    request->send(SPIFFS, "/system.html", String(), false, processor);
  });

 server.on("/system.html", HTTP_POST, [](AsyncWebServerRequest *request) {
   Serial.println("\n/system.html POST");
   currentPage=systemPage;
   int parameters = request->params();
   for(int i=0;i<parameters;i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      if(p->isPost()){
        Serial.printf("POST[%s]: (%s)\n", p->name().c_str(), p->value().c_str());

        if (p->name()== "clocksName" ){
          if (strlen(p->value().c_str())>0){
            Serial.printf("Change Clock Name for %s \n", p->value().c_str());
            params.setClockName( p->value());
          }
        }

        if (p->name()== "NTPServer" ){
          if (strlen(p->value().c_str())>0){
            Serial.printf("Change NTPServer Name for %s \n", p->value().c_str());
            params.setTimeServer( p->value());
          }
        }

        if (p->name()== "update" && p->value() == "on"){
          Serial.println("update files");
         upFlag=true;
        }
       
        if (p->name()== "reset" && p->value() == "on"){
          Serial.println("reset");
          if (p->name()== "factoryReset" && p->value() == "Factory Reset"){
            formatSPIFFS();
            params.factoryReset();
          }
          ESP.restart();
        }
      }
    }
    request->send(SPIFFS, "/system.html", String(), false, processor);
  });

 
  server.on("/portal.html", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    Serial.println("on Portal GET");
    currentPage=wifiPage;
    request->send(SPIFFS, "/portal.html", String(), false, PORTAL_processor);
  });
  
  server.on("/portal.html", HTTP_POST, [](AsyncWebServerRequest *request)
  {
    currentPage=wifiPage;
   Serial.println("on Portal POST");
    int parameters = request->params();
    for(int i=0;i<parameters;i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      if(p->isPost()){
        Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
        if (p->value() != "")
        {
          Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
          int ssid = p->name().toInt();
          
          Serial.printf("setting up SSID:Pwd %s:%s",WiFi.SSID(ssid).c_str(), p->value().c_str());
          Params params;
          params.saveWiFiSSID(WiFi.SSID(ssid).c_str());
          params.saveWiFiPSK(p->value().c_str());
          params.setWiFiCredentialsValidity(true);
          
          ESP.reset();  
        }   
      }
    }
    request->send(SPIFFS, "/portal.html", String(), false, PORTAL_processor);
  });

  if (asPortal==true)  { 
     server.onNotFound([](AsyncWebServerRequest *request) 
     {
      Serial.println("onNotFound Portal");
       currentPage=wifiPage;
   
       int params = request->params();
       for(int i=0;i<params;i++)
       {
         AsyncWebParameter* p = request->getParam(i);
           if(p->isPost())
           {
             Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
             if (p->value() != "")
             {
               Serial.printf("POST[%s]: %s\n", p->name().c_str(), p->value().c_str());
               int ssid = p->name().toInt();
               Serial.printf("setting up SSID:Pwd %s:%s",WiFi.SSID(ssid).c_str(), p->value().c_str());
               Params params;
               params.saveWiFiSSID(WiFi.SSID(ssid).c_str());
               params.saveWiFiPSK(p->value().c_str());
               params.setWiFiCredentialsValidity(true);
               ESP.reset();  
            }   
          }
      }
      
      request->send(SPIFFS, "/portal.html", String(), false, PORTAL_processor);
    });

   } 
  else {
     server.onNotFound([](AsyncWebServerRequest *request) { 
       currentPage = homePage;
       request->send(SPIFFS, "/index.html", String(), false, processor);
     }); 
   }

  server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(401);
  });
  
  server.on("/login", HTTP_GET, [](AsyncWebServerRequest *request){
    
    if (params.getWebAuthentication())
    {
    if(!request->authenticate(params.webLogin.c_str(), params.webPassword.c_str() ))
        return request->requestAuthentication();
    }
    request->send(200, "text/plain", "Login Success!");
  });

    server.on("/force", HTTP_GET, [](AsyncWebServerRequest *request){
    upFlag=true;
    request->send(200, "text/plain", "Force OTA");
  });

  server.on("/log", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/log.html", String(), false, log_processor);
  });
  
  server.on("/fmt", HTTP_GET, [](AsyncWebServerRequest *request){
    upFlag = true;
    fmtFlag = true;
    request->send(SPIFFS, "/index.html", String(), false, log_processor);
  });


 
  server.on("/dir", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", SPIFFSListingWeb());
  });

  // Start server

  server.begin();
}
