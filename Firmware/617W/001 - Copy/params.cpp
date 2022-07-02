 
#include "Arduino.h"
#include "params.h"
#include "EEPROM.h"

// eeprom locations for wifi cred

const int _eeWiFiPSK = 470;
const int _eeWiFiSSID = 430;

const int _eeWebPassword = 415;
const int _eeWebLogin = 400;


/* 0 to 128 reseved for OTA*/
const int _eeWiFiRebootCount=208;
const int _eevalidEEPROM = 209;

const int _eetimeFormat = 210;
const int _eezeroBlanking = 211;
const int _eetubeIntensity = 212;

const int _eeSecondOffHours = 214;
const int _eeSecondOffMinutes = 215;
const int _eeSecondOnHours = 216;
const int _eeSecondOnMinutes = 217;
const int _eeRebootCount = 218;
const int _eeWiFiCredValidity = 219;
const int _eeOTAReboot = 220;
const int _eeDSTZone = 221;
const int _eeTimeZone = 222;
const int _eeBlankingAllowed = 223;
const int _eeAuthenticate = 224;
const int _eeClockName = 225;
//
const int _eeTimeServer= 260;

String timeZoneName[] = { "None. DST settings used.",
                          "(GMT -12:00) Eniwetok",
                          "(GMT -11:00) Midway Island",
                          "(GMT -10:00) Hawaii",
                          "(GMT - 9:30) Taiohae",
                          "(GMT - 9:00) Alaska",
                          "(GMT - 8:00) Pacific Time (US & Canada)",
                          "(GMT - 7:00) Mountain Time (US & Canada)",
                          "(GMT - 6:00) Central Time (US & Canada)",
                          "(GMT - 5:00) Eastern Time (US & Canada)",
                          "(GMT - 4:30) Caracas",
                          "(GMT - 4:00) Atlantic Time (Canada)",
                          "(GMT - 3:30) Newfoundland",
                          "(GMT - 3:00) Brazil",
                          "(GMT - 2:00) Mid-Atlantic",
                          "(GMT - 1:00) Azores",
                          "(GMT + 0:00) Western Europe Time",
                          "(GMT + 1:00) Lausanne, Berne, Paris, Brussels",
                          "(GMT + 2:00) Kaliningrad",
                          "(GMT + 3:30) Tehran",
                          "(GMT + 4:00) Abu Dhabi",
                          "(GMT + 4:30) Kabul",
                          "(GMT + 5:00) Ekaterinburg",
                          "(GMT + 5:30) Bombay",
                          "(GMT + 5:45) Kathmandu",
                          "(GMT + 6:00) Almaty",
                          "(GMT + 6:30) Yangon",
                          "(GMT + 7:00) Bangkok",
                          "(GMT + 8:00) Beijing",
                          "(GMT + 8:45) Eucla",
                          "(GMT + 9:00) Tokyo",
                          "(GMT + 9:30) Adelaide",
                          "(GMT +10:00) Eastern Australia",
                          "(GMT +10:30) Lord Howe Island",
                          "(GMT +11:00) Magadan",
                          "(GMT +11:30) Norfolk Island",
                          "(GMT +12:00) Auckland",
                          "(GMT +12:45) Chatham Islands",
                          "(GMT +13:00) Apia",
                          "(GMT +14:00) Line Islands"
  };
                            
/*******************************************************************************/
Params::Params()
{
  EEPROM.begin(512);

  if (readInt(_eevalidEEPROM)!= 42)
  { 
    Serial.println("Invalid EEPROM : Parameters back to Factory");
    factoryReset();
  }
  
  _timeFormat             = (readInt(_eetimeFormat)==h12)?h12:h24;
  _WiFiSSID               = readString(_eeWiFiSSID);
  _WiFiPSK                = readString(_eeWiFiPSK);
  _isZeroBlanked          = readBool(_eezeroBlanking)==1;
  _secondsBlankingAllowed = readBool(_eeBlankingAllowed);
  _luminosityMode         = readInt(_eetubeIntensity);
  _timeZone               = readInt(_eeTimeZone);
  _DSTZone                = readInt(_eeDSTZone);
  _timeServer             = readString(_eeTimeServer);
  _timeOffsetIndex        = readInt(_eeTimeZone);
  _WiFiCredsValidity      = readBool(_eeWiFiCredValidity);
  _clockName              = readString(_eeClockName);
  _WiFiRebootCount        = readByte(_eeWiFiRebootCount);
}



/*******************************************************************************/
void Params::writeInt(int _address, int _value)
{
  EEPROM.write(_address, _value);
  EEPROM.commit();
}


/*******************************************************************************/
byte Params::readInt(int address)
{
  int value;
  value = EEPROM.read(address);
  return value;
}

void Params::writeByte(int _address, byte _value){
  EEPROM.write(_address, _value);
  EEPROM.commit();
}

byte Params::readByte(int address){
  return EEPROM.read(address);
}


void Params::writeString(String strToSave, int eepromBase){
  int i;
  for (i = 0; i < strToSave.length(); ++i)
  {
  	EEPROM.write(eepromBase + i, strToSave[i]);
  }
  EEPROM.write(eepromBase + i, '|');
  EEPROM.commit();
}

	
String Params::readString(int eepromBase){
  String eeStr="";
	for (int i = 0; i < 33; ++i)
	{
	  if (EEPROM.read(i + eepromBase) == '|') break;
		  eeStr += char(EEPROM.read(i + eepromBase));
	}
	return eeStr;
}

  /*******************************************************************************/
  void Params::writeBool(int _address, bool _value)
  {
    EEPROM.write(_address, (_value)?1:0);
    EEPROM.commit();
  }
  
  /*******************************************************************************/
  bool Params::readBool(int address)
  {
    return EEPROM.read(address)==1;
  }
  /*******************************************************************************/

  void Params::saveWebPassword(String webPassword)
  {
    _webPassword = webPassword;
    writeString(_webPassword, _eeWebPassword);
  }

 
  void Params::saveWebLogin(String webLogin)
  {
    _webLogin = webLogin;
    writeString(_webLogin, _eeWebLogin);
  }

  
  bool Params::getWebAuthentication()
  {
    return (readInt(_eeAuthenticate) == 42);
  }

    void Params::setWebAuthentication(bool validity)
  {
    writeInt(_eeAuthenticate, (validity) ? 42 : 0);
  }


	/*******************************************************************************
	*
	* input : none
	* output:
	*******************************************************************************/
    void Params::setWiFiCredentialsValidity(bool validity)
	{
    _WiFiCredsValidity = validity;
		writeBool(_eeWiFiCredValidity,_WiFiCredsValidity);
	}

	/*******************************************************************************
	*
	* input : none
	* output:
	*******************************************************************************/
    void Params::saveWiFiSSID(String SSID)
	{
    _WiFiSSID = SSID;
		writeString(_WiFiSSID, _eeWiFiSSID);
	}

	/*******************************************************************************
	*
	* input : none
	* output:
	*******************************************************************************/
    void Params::saveWiFiPSK(String PSK)
	{  
    _WiFiPSK = PSK;
		writeString(_WiFiPSK, _eeWiFiPSK);
	}


/*******************************************************************************/
void Params::saveWiFi(String newSSID, String newPSK)
{
	saveWiFiPSK(newPSK);
	saveWiFiSSID(newSSID);
	setWiFiCredentialsValidity(true);
}

/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::setTimeFormat(eTimeFormat timeformat)
{
  _timeFormat =  timeformat;
  writeInt(_eetimeFormat, _timeFormat);
}

/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::setLuminosityMode(int mode)
{
	Serial.printf("\nW LuminosityMode %d\n", mode);
 if (mode <0) mode=0;
 if (mode >9) mode=9;
  _luminosityMode = mode;
	writeInt(_eetubeIntensity, _luminosityMode );
}



/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::setZeroBlanking(bool isBlanked)
{
  _isZeroBlanked = isBlanked;
	writeInt(_eezeroBlanking,_isZeroBlanked);
}





/* ************************************************************** */
//
//
/* ************************************************************** */
int Params::getRebootCount()
{
	return readInt(_eeRebootCount);
}






/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::incRebootCount()
{
	int rebootCount = readInt(_eeRebootCount);
	rebootCount = rebootCount + 1;
	writeInt(_eeRebootCount,rebootCount);
}

/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::resetRebootCount()
{
	writeInt(_eeRebootCount,0);
}

/* ************************************************************** */
//
/* ************************************************************** */
void Params::factoryReset()
{
	Serial.println("Factory Reset");
	setWiFiCredentialsValidity(false);
	setTimeFormat(h24);
	setZeroBlanking(false);
	setSecondsBlankingAllowed(false);
	setLuminosityMode(0);
	setDSTZone(1);// DST = GMZ;
	setTimeOffsetIndex(0); // do time zone used

  setWebAuthentication(false);
  saveWebPassword("Steam");
  saveWebLogin("Clock");

  setClockName("No 614W");
  setTimeServer("ch.pool.ntp.org");
  setWiFiRebootCount(0);
  writeInt(_eevalidEEPROM,42);
  _validEEPROM=true;
}

/* ************************************************************** */
//
//
/* ************************************************************** */
void Params::setIsOTAReboot(bool OTAReboot)
{
	writeInt(_eeOTAReboot, (OTAReboot)?42:0);
}

/* ************************************************************** */
//
//
/* ************************************************************** */
bool Params::getIsOTAReboot()
{
	return readInt(_eetubeIntensity)==42;
}

// ------------------------------------------------------------------
void Params::setDSTZone(int dstZone)
{
  _DSTZone =dstZone ;
	writeInt(_eeDSTZone, _DSTZone);

 
 if (_DSTZone!=0)
 {  
    Serial.println("by rule _timeOffsetIndex=;");
    _timeOffsetIndex=0;
    writeInt(_eeTimeZone, 0);
 }  
}


// ------------------------------------------------------------------
void Params::setTimeOffsetIndex(int timeOffsetIndex)
{
  if (timeOffsetIndex<0  ) timeOffsetIndex = 0;
  if (timeOffsetIndex >39) timeOffsetIndex = 0;
  
  _timeOffsetIndex=timeOffsetIndex;
	writeInt(_eeTimeZone, timeOffsetIndex);

  if (_timeOffsetIndex!=0)
  {
     Serial.println("by rule _DSTZone=0");
    _DSTZone=0;
    writeInt(_eeDSTZone, 0);
  }
}


String Params::getTimezoneName(int timeZone)
{
  switch (timeZone){
    case 0: return "None. DST settings used.";break;
    case 1: return "(GMT -12:00) Eniwetok";break;
    case 2: return "(GMT -11:00) Midway Island";break;
    case 3: return "(GMT -10:00) Hawaii";break;
    case 4: return "(GMT - 9:30) Taiohae";break;
    case 5: return "(GMT - 9:00) Alaska";break;
    case 6: return "(GMT - 8:00) Pacific Time (US & Canada)";break;
    case 7: return "(GMT - 7:00) Mountain Time (US & Canada)";break;
    case 8: return "(GMT - 6:00) Central Time (US & Canada)";break;
    case 9: return "(GMT - 5:00) Eastern Time (US & Canada)";break;
    case 10: return "(GMT - 4:30) Caracas";break;
    case 11: return "(GMT - 4:00) Atlantic Time (Canada)";break;
    case 12: return "(GMT - 3:30) Newfoundland";break;
    case 13: return "(GMT - 3:00) Brazil";break;
    case 14: return "(GMT - 2:00) Mid-Atlantic";break;
    case 15: return "(GMT - 1:00) Azores";break;
    case 16: return "(GMT + 0:00) Western Europe Time";break;
    case 17: return "(GMT + 1:00) Lausanne, Berne, Paris, Brussels";break;
    case 18: return  "(GMT + 2:00) Kaliningrad";break;
    case 19: return "(GMT + 3:30) Tehran";break;
    case 20: return "(GMT + 4:00) Abu Dhabi";break;
    case 21: return "(GMT + 4:30) Kabul";break;
    case 22: return  "(GMT + 5:00) Ekaterinburg";break;
    case 23: return  "(GMT + 5:30) Bombay";break;
    case 24: return  "(GMT + 5:45) Kathmandu";break;
    case 25: return  "(GMT + 6:00) Almaty";break;
    case 26: return   "(GMT + 6:30) Yangon";break;
    case 27: return   "(GMT + 7:00) Bangkok";break;
    case 28: return   "(GMT + 8:00) Beijing";break;
    case 29: return   "(GMT + 8:45) Eucla";break;
    case 30: return   "(GMT + 9:00) Tokyo";break;
    case 31: return   "(GMT + 9:30) Adelaide";break;
    case 32: return   "(GMT +10:00) Eastern Australia";break;
    case 33: return   "(GMT +10:30) Lord Howe Island";break;
    case 34: return   "(GMT +11:00) Magadan";break;
    case 35: return   "(GMT +11:30) Norfolk Island";break;
    case 36: return   "(GMT +12:00) Auckland";break;
    case 37: return   "(GMT +12:45) Chatham Islands";break;
    case 38: return   "(GMT +13:00) Apia";break;
    case 39: return   "(GMT +14:00) Line Islands";break;
    default : return "oob";  
  }
}

String Params::getDSTName(int dst)
{
  switch (dst) {
    case 0: return "None, Timezone settings used.";break;
    case 1: return "GMT";break;
    case 2: return "Western Europe";break;
    case 3: return "Center Europe";break;
    case 4: return "Eastern Europe";break;
    case 5: return "US Pacific Standard";break;
    case 6: return "US Mountain Standard";break;
    case 7: return "US Central Standard Time";break;
    case 8: return "AU Eastern Standard Time";break;
    case 9: return "US Eastern Standard Time";break;
    default: return "NONE";
  }
}

String Params::getTubeIntensityLabel(int pos)
{
  switch (pos){
    case 0 : return "Automatic";break;
    case 1 : return "Minimum Light";break;
    case 2 : return "2 on 9";break;
    case 3 : return "3 on 9";break;
    case 4 : return "4 on 9";break;
    case 5 : return "5 on 9";break;
    case 6 : return "6 on 9";break;
    case 7 : return "7 on 9";break;
    case 8 : return "8 on 9";break;
    case 9 : return "Full Light";break;
    default: return "OOB";
  }
}

void Params::setSecondsBlankingAllowed(bool status)
{
	_secondsBlankingAllowed = status;
	writeBool(_eeBlankingAllowed, _secondsBlankingAllowed);
}

void Params::setClockName (String clockName){
  _clockName = clockName;
  writeString(_clockName,_eeClockName);
  Serial.println(readString(_eeClockName));
}

void Params::setTimeServer(String timeServer){
  _timeServer = timeServer;
  writeString(_timeServer, _eeTimeServer); 
}

void Params::setWiFiRebootCount(byte count){
  _WiFiRebootCount = count;
  writeByte(_eeWiFiRebootCount, _WiFiRebootCount);
}

void Params::displayParams()
{
  Serial.println ("\n******************************");
  Serial.println ((_WiFiCredsValidity)?"Wifi creds are valid": "Wifi creds are invalid");
  Serial.println ((_timeFormat==h12)?"Time Format is 12h":"Time Format is 24h");
  Serial.println ((_isZeroBlanked)? "Leading Zero is blanked": "Leading Zero is not blanked") ;
  Serial.println ((_secondsBlankingAllowed)?"Seconds can be blanked":"Seconds cannot be blanked");
  Serial.print   ("Luminosity mode is ");
  Serial.println (_luminosityMode);
  
  Serial.print  ("DST zone is #");
  Serial.print  (_DSTZone);
  Serial.print  (": ");
  Serial.println(getDSTName(_DSTZone));
  
  Serial.print  ("Time Offset Index is #");
  Serial.print  (_timeOffsetIndex);
  Serial.print  (": ");
  Serial.println(getTimezoneName(_timeOffsetIndex));
  Serial.print  ("Clock's Name :"); Serial.println(_clockName);
  Serial.print  ("NTP Server :"); Serial.println(_timeServer);
  Serial.print  ("Wifi Reboot Count :");Serial.println(_WiFiRebootCount);
  
  
  Serial.println("******************************");
}
