#include "IN17.h"

void IN17::encode(byte expanderAdd, byte toDisplay, byte *bankA, byte *bankB, byte dot){
  if (dot >0) dot = 1;

  switch (toDisplay)
  {
    case 0:  *bankA = 16 + dot; *bankB = 0;  break;
    case 1:  *bankA = 8 + dot;  *bankB = 0;  break;
    case 2:  *bankA = 2 + dot;  *bankB = 0;  break;
    case 3:  *bankA = 1 + dot;  *bankB = 0;  break;
    case 4:  *bankA = 4 + dot;  *bankB = 0;  break;
    case 5:  *bankA = 0 + dot;  *bankB = 16; break;
    case 6:  *bankA = 0 + dot;  *bankB = 8 ; break;
    case 7:  *bankA = 0 + dot;  *bankB = 4 ; break;
    case 8:  *bankA = 0 + dot;  *bankB = 32; break;
    case 9:  *bankA = 0 + dot;  *bankB = 2;  break;
    default: *bankA = 0;        *bankB = 0;
  }
}
