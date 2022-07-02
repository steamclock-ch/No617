
//United Kingdom (London, Belfast)
TimeChangeRule BST = { "BST", Last, Sun, Mar, 1, 60 };        //British Summer Time
TimeChangeRule GMT = { "GMT", Last, Sun, Oct, 2, 0 };         //Standard Time
Timezone UK(BST, GMT);

//WET / WEST TODO
TimeChangeRule WET= { "WET", Last, Sun, Mar, 1, 60 };        //West European Standard Time
TimeChangeRule WEST = { "WEST", Last, Sun, Oct, 2, 0 };      //West European Summer Time
Timezone WE(WET, WEST);

//Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = { "CEST", Last, Sun, Mar, 2, 120 };     //Central European Summer Time
TimeChangeRule CET  = { "CET ", Last, Sun, Oct, 3, 60 };       //Central European Standard Time
Timezone CE(CEST, CET);

//EET / EEST TODO
TimeChangeRule EET = { "EET", Last, Sun, Mar, 4, 120 };        //East European Standard Time
TimeChangeRule EEST = { "EEST", Last, Sun, Oct, 3, 180 };      //East European Summer Time
Timezone EE(EET, EEST);


//US Pacific Time Zone (Las Vegas, Los Angeles)
TimeChangeRule usPDT = { "PDT", Second, dowSunday, Mar, 2, -420 }; //-0800
TimeChangeRule usPST = { "PST", First, dowSunday, Nov, 2, -480 };
Timezone usPT(usPDT, usPST);

//US Mountain Time Zone (Denver, Salt Lake City)
TimeChangeRule usMDT = { "MDT", Second, dowSunday, Mar, 2, -360 }; //-0700
TimeChangeRule usMST = { "MST", First, dowSunday, Nov, 2, -420 };
Timezone usMT(usMDT, usMST);

//US Central Time Zone (Chicago, Houston)
TimeChangeRule usCDT = { "CDT", Second, dowSunday, Mar, 2, -300 }; //-0600
TimeChangeRule usCST = { "CST", First, dowSunday, Nov, 2, -360 };
Timezone usCT(usCDT, usCST);

//US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEDT = { "EDT", Second, Sun, Mar, 2, -240 };  //Eastern Daylight Time = UTC - 4 hours
TimeChangeRule usEST = { "EST", First, Sun, Nov, 2, -300 };   //Eastern Standard Time = UTC - 5 hours
Timezone usET(usEDT, usEST);

//Australia Eastern Time Zone (Sydney, Melbourne)
TimeChangeRule aEDT = { "AEDT", First, Sun, Oct, 2, 660 };    //UTC + 11 hours
TimeChangeRule aEST = { "AEST", First, Sun, Apr, 3, 600 };    //UTC + 10 hours
Timezone ausET(aEDT, aEST);




TimeChangeRule aGMT1 = {"GMT1", First, Mon, Jan, 1,-720};//GMT -12
Timezone GMT1(aGMT1, aGMT1);

TimeChangeRule aGMT2 = {"GMT2", First, Mon, Jan, 1,-660};//GMT - 11
Timezone GMT2(aGMT2, aGMT2);

TimeChangeRule aGMT3 = {"GMT3", First, Mon, Jan, 1,-60};//GMT - 10
Timezone GMT3(aGMT3, aGMT3);

TimeChangeRule aGMT4 = { "GMT4", First, Mon, Jan, 1,-570 };//GMT -; 9.5
Timezone GMT4(aGMT4, aGMT4);

TimeChangeRule aGMT5 = {"GMT5", First, Mon, Jan, 1,-540};//GMT - 9
Timezone GMT5(aGMT5, aGMT5);

TimeChangeRule aGMT6 = {"GMT6", First, Mon, Jan, 1,-480};//GMT - 8
Timezone GMT6(aGMT6, aGMT6);

TimeChangeRule aGMT7 = {"GMT7", First, Mon, Jan, 1,-420};//GMT - 7
Timezone GMT7(aGMT7, aGMT7);

TimeChangeRule aGMT8 = {"GMT8"   , First, Mon, Jan, 1,-360};//GMT - 6
Timezone GMT8(aGMT8, aGMT8);

TimeChangeRule aGMT9 = { "GMT9"   , First, Mon, Jan, 1,-300 };//GMT -; 5
Timezone GMT9(aGMT9, aGMT9);

TimeChangeRule aGMT10 = {"GMT10" , First, Mon, Jan, 1,-270}; //GMT -4.5
Timezone GMT10(aGMT10, aGMT10);

TimeChangeRule aGMT11 = {"GMT11" , First, Mon, Jan, 1,-240}; // GMT -4
Timezone GMT11(aGMT11, aGMT11);

TimeChangeRule aGMT12 = {"GMT12" , First, Mon, Jan, 1,-210}; // GMT -3.5
Timezone GMT12(aGMT12, aGMT12);

TimeChangeRule aGMT13 = {"GMT13" , First, Mon, Jan, 1,-180};  //GMT -3
Timezone GMT13(aGMT13, aGMT13);

TimeChangeRule aGMT14 = {"GMT14" , First, Mon, Jan, 1,-120}; //GMT -2
Timezone GMT14(aGMT14, aGMT14);

TimeChangeRule aGMT15 = {"GMT15" , First, Mon, Jan, 1,-60}; // GMT -1
Timezone GMT15(aGMT15, aGMT15);


Timezone GMT16(GMT, GMT);


TimeChangeRule aGMT17 = {"GMT17" , First, Mon, Jan, 1,60}; // GMT+1
Timezone GMT17(aGMT17, aGMT17);

TimeChangeRule aGMT18 = {"GMT18" , First, Mon, Jan, 1,120}; // GMT+2
Timezone GMT18(aGMT18, aGMT18);

TimeChangeRule aGMT19 = {"GMT19" , First, Mon, Jan, 1,210}; // GMT + 3.5
Timezone GMT19(aGMT19, aGMT19);

TimeChangeRule aGMT20 = {"GMT20" , First, Mon, Jan, 1,240}; // GTMT +4 
Timezone GMT20(aGMT20, aGMT20);

TimeChangeRule aGMT21 = {"GMT21" , First, Mon, Jan, 1,270}; // GMT + 4.5
Timezone GMT21(aGMT21, aGMT21);

TimeChangeRule aGMT22 = {"GMT22" , First, Mon, Jan, 1,300};//GMT +5
Timezone GMT22(aGMT22, aGMT22);

TimeChangeRule aGMT23 = {"GMT23" , First, Mon, Jan, 1,330};//GMT +5.5
Timezone GMT23(aGMT23, aGMT23);

TimeChangeRule aGMT24 = {"GMT24" , First, Mon, Jan, 1,345};//GMT +5.75
Timezone GMT24(aGMT24, aGMT24);

TimeChangeRule aGMT25 = {"GMT25" , First, Mon, Jan, 1,360};//GMT +6
Timezone GMT25(aGMT25, aGMT25);

TimeChangeRule aGMT26 = {"GMT26" , First, Mon, Jan, 1,390};//GMT +6.5
Timezone GMT26(aGMT26, aGMT26);

TimeChangeRule aGMT27 = {"GMT27" , First, Mon, Jan, 1,420};//GMT +7
Timezone GMT27(aGMT27, aGMT27);

TimeChangeRule aGMT28 = {"GMT28" , First, Mon, Jan, 1,480}; //GMT +8
Timezone GMT28(aGMT28, aGMT28);

TimeChangeRule aGMT29 = {"GMT29" , First, Mon, Jan, 1,525};//GMT +8.75
Timezone GMT29(aGMT29, aGMT29);

TimeChangeRule aGMT30 = {"GMT30" , First, Mon, Jan, 1,540};//GMT +9
Timezone GMT30(aGMT30, aGMT30);

TimeChangeRule aGMT31 = {"GMT31" , First, Mon, Jan, 1,570};//GMT +9.5
Timezone GMT31(aGMT31, aGMT31);

TimeChangeRule aGMT32 = {"GMT32" , First, Mon, Jan, 1,600};//GMT +10
Timezone GMT32(aGMT32, aGMT32);

TimeChangeRule aGMT33 = {"GMT33" , First, Mon, Jan, 1,630};//GMT +10.5
Timezone GMT33(aGMT33, aGMT33);

TimeChangeRule aGMT34 = {"GMT34" , First, Mon, Jan, 1,660};//GMT +11
Timezone GMT34(aGMT34, aGMT34);

TimeChangeRule aGMT35 = {"GMT35" , First, Mon, Jan, 1,690};//GMT +11.5
Timezone GMT35(aGMT35, aGMT35);

TimeChangeRule aGMT36 = {"GMT36" , First, Mon, Jan, 1,720};//GMT +12
Timezone GMT36(aGMT36, aGMT36);

TimeChangeRule aGMT37 = {"GMT37" , First, Mon, Jan, 1,765};//GMT +12.75
Timezone GMT37(aGMT37, aGMT37);

TimeChangeRule aGMT38 = {"GMT38" , First, Mon, Jan, 1,780};//GMT +13
Timezone GMT38(aGMT38, aGMT38);

TimeChangeRule aGMT39 = {"GMT39" , First, Mon, Jan, 1,840};//GMT +14
Timezone GMT39(aGMT39, aGMT39);

TimeChangeRule *tcr;


/* -------------------------------------------------- */
time_t  getTime(int DSTZone, int _timeZoneIndex , time_t time)
{
  switch (DSTZone)
  {
  case 1/*EUGMT*/:  // retVal.TZName = (retVal.isDST) ? "BST" : "GMT";
    time = UK.toLocal(time, &tcr);
    break;
  case 2 /*EUWET*/:   //retVal.TZName = (retVal.isDST) ? "WET" : "WEST";
    time = WE.toLocal(time, &tcr);
    break;
  case 3/*EUCET*/:   //retVal.TZName = (retVal.isDST) ? "CEST" : "CET";
    time = CE.toLocal(time, &tcr);
    break;
  case 4/*EUEET*/:   //retVal.TZName = (retVal.isDST) ? "CEST" : "CET";
    time = CE.toLocal(time, &tcr);
    break;
  case 5/*USPT*/:    //retVal.TZName = (retVal.isDST) ? "PDT" : "PST";
    time = usPT.toLocal(time, &tcr);
    break;
  case 6/*USMT*/:    //retVal.TZName = (retVal.isDST) ? "MST" : "CET";
    time = usMT.toLocal(time, &tcr);
    break;
  case 7/*USCT*/:    //retVal.TZName = (retVal.isDST) ? "CST" : "CDT";
    time = usCT.toLocal(time, &tcr);
    break;
  case 8/*AUET*/: //retVal.TZName = (retVal.isDST) ? "AEST" : "AEDT";
      time = ausET.toLocal(time, &tcr);
      break;
  case 9/*USET*/:   // retVal.TZName = (retVal.isDST) ? "EDT" : "EST";
    time = usET.toLocal(time, &tcr);
    break;
  
  default : //retVal.TZName = (retVal.isDST) ? "BST" : "GMT";
    time = UK.toLocal(time, &tcr);
    break;
  }

  if (DSTZone == 0)
  {
    switch (_timeZoneIndex)
    {
      case 1 : time = GMT1.toLocal(time, &tcr);break;
      case 2 : time = GMT2.toLocal(time, &tcr);break;
      case 3 : time = GMT3.toLocal(time, &tcr);break;
      case 4 : time = GMT4.toLocal(time, &tcr);break;
      case 5 : time = GMT5.toLocal(time, &tcr);break;
      case 6 : time = GMT6.toLocal(time, &tcr);break;
      case 7 : time = GMT7.toLocal(time, &tcr);break;
      case 8 : time = GMT8.toLocal(time, &tcr);break;
      case 9 : time = GMT9.toLocal(time, &tcr);break;
      case 10: time = GMT10.toLocal(time, &tcr);break;
      case 11: time = GMT11.toLocal(time, &tcr);break;
      case 12: time = GMT12.toLocal(time, &tcr);break;
      case 13: time = GMT13.toLocal(time, &tcr);break;
      case 14: time = GMT14.toLocal(time, &tcr);break;
      case 15: time = GMT15.toLocal(time, &tcr);break;
    
      case 16: time = GMT16.toLocal(time, &tcr);break;
    
      case 17: time = GMT17.toLocal(time, &tcr);break;
      case 18: time = GMT18.toLocal(time, &tcr);break;
      case 19: time = GMT19.toLocal(time, &tcr);break;
      case 20: time = GMT20.toLocal(time, &tcr);break;
      case 21: time = GMT21.toLocal(time, &tcr);break;
      case 22: time = GMT22.toLocal(time, &tcr);break;
      case 23: time = GMT23.toLocal(time, &tcr);break;
      case 24: time = GMT24.toLocal(time, &tcr);break;
      case 25: time = GMT25.toLocal(time, &tcr);break;
      case 26: time = GMT26.toLocal(time, &tcr);break;
      case 27: time = GMT27.toLocal(time, &tcr);break;
      case 28: time = GMT28.toLocal(time, &tcr);break;
      case 29: time = GMT29.toLocal(time, &tcr);break;
      case 30: time = GMT30.toLocal(time, &tcr);break;
      case 31: time = GMT31.toLocal(time, &tcr);break;
      case 32: time = GMT32.toLocal(time, &tcr);break;
      case 33: time = GMT33.toLocal(time, &tcr);break;
      case 34: time = GMT34.toLocal(time, &tcr);break;
      case 35: time = GMT35.toLocal(time, &tcr);break;
      case 36: time = GMT36.toLocal(time, &tcr);break;
      case 37: time = GMT37.toLocal(time, &tcr);break;
      case 38: time = GMT38.toLocal(time, &tcr);break;
      case 39: time = GMT39.toLocal(time, &tcr);break;
     
      default:  time = GMT16.toLocal(time, &tcr);break;
      break;
    }
    //retVal.TZName = TimeZones[_timeZoneIndex].shortName.c_str();
  }
      
  return time;
}

// Function to return the compile date and time as a time_t value
time_t compileTime()
{
    const time_t FUDGE(10);     // fudge factor to allow for compile time (seconds, YMMV)
    const char *compDate = __DATE__, *compTime = __TIME__, *months = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char chMon[4], *m;
    tmElements_t tm;

    strncpy(chMon, compDate, 3);
    chMon[3] = '\0';
    m = strstr(months, chMon);
    tm.Month = ((m - months) / 3 + 1);

    tm.Day = atoi(compDate + 4);
    tm.Year = atoi(compDate + 7) - 1970;
    tm.Hour = atoi(compTime);
    tm.Minute = atoi(compTime + 3);
    tm.Second = atoi(compTime + 6);
    time_t t = makeTime(tm);
    return t + FUDGE;           // add fudge factor to allow for compile time
}



void setupTime()
{
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  setSyncInterval(10);//60s*60m*6h
  
}
