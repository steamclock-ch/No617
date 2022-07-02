
#ifndef IN17_h
#define IN17_h

  #if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #else
  #include "WProgram.h"
  #endif
  #include <IPAddress.h>

  #include <NixieDisplay.h>

  static const char ClockType[] = "No617W";

  const byte _blank = 10;

  class IN17:public NixieDisplay {
    private:
      void encode(byte expanderAdd, byte toDisplay, byte *bankA, byte *bankB, byte dot);
  };

#endif
