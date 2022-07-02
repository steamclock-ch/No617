// N614_EEPROM.h

#ifndef _N614_EEPROM_h
#define _N614_EEPROM_h

#include "Arduino.h"
#include <EEPROM.h>

  enum eTimeFormat{h12,h24};


class Params
{
   
  private:
    void    writeInt(int _address, int _value);
    byte    readInt(int address);
    void    writeString(String strToSave, int eepromBase);
    void    writeBool(int _address, bool _value);
    bool    readBool(int address);
    void    writeByte(int _address, byte _value);
    byte    readByte(int _address);
    String  readString(int eepromBase);
    int     getWiFiCredentialsValidity();
    
    eTimeFormat     _timeFormat;
    String  _WiFiSSID;
    String  _WiFiPSK;
    bool    _isZeroBlanked;
    bool    _secondsBlankingAllowed;
    int     _luminosityMode;
    int     _timeZone;
    int    _DSTZone;
    String _timeServer;
    int    _timeOffsetIndex;
    bool   _validEEPROM;
    bool   _WiFiCredsValidity;
    String _clockName;
    String _webPassword;
    String _webLogin;
    byte   _WiFiRebootCount;
    

  public:
    Params(); 

    const String&       WiFiSSID = _WiFiSSID;      
    const String&       WiFiPSK = _WiFiPSK;
    const bool&         isZeroBlanked = _isZeroBlanked;
    const bool&         secondsBlankingAllowed = _secondsBlankingAllowed;
    const int&          luminosityMode         = _luminosityMode; 
    const int&          timeZone               = _timeZone;
    const int&          DSTZone                = _DSTZone;
    const String&       timeServer             = _timeServer;
    const int&          timeOffsetIndex        = _timeOffsetIndex;
    const eTimeFormat&  timeFormat             = _timeFormat;
    const bool&         WiFiCredsValidity      = _WiFiCredsValidity;
    const String&       clockName              = _clockName;
    const String&       webPassword            = _webPassword;
    const String&       webLogin               = _webLogin;
    const byte&         WiFiRebootCount        = _WiFiRebootCount;
    
    void   begin();
    void   displayParams();
    String getTubeIntensityLabel(int pos);
    bool   WiFiCredValidity();
    void   setWiFiCredentialsValidity(bool validity);
    void   saveWiFiSSID(String SSID);
    void   saveWiFiPSK(String PSK);

  
    void   saveWebPassword(String webPassword);
    void   saveWebLogin(String webLogin);
    bool   getWebAuthentication();
    void   setWebAuthentication(bool validity);
      

    void saveWiFi(String newSSID, String newPSK);
    void setTimeFormat(eTimeFormat timeformat);
    void setLuminosityMode(int mode);
    void setClockName (String clockName);
    void setTimeServer(String timeServer);

    //bool isZeroBlanked();
    void setZeroBlanking(bool isBlanked);
    int getRebootCount();

    void incRebootCount();
    void resetRebootCount();
    void factoryReset();
    void setIsOTAReboot(bool OTAReboot);
    bool getIsOTAReboot();
    void setDSTZone(int dstZone);
    
    String getDSTName(int dst);
    void setTimeOffsetIndex(int timeOffsetIndex);
    int  getTimeOfsetIndex();
    String getTimezoneName(int timeZone);
    void setSecondsBlankingAllowed(bool status);
    void setWiFiRebootCount(byte count);
    
    void setup();
};

#endif
