

//*********************************************************
void printErrorMessage(uint8_t e, bool eol = true){
  switch (e) {
  case SPIFFSIniFile::errorNoError:
    Serial.print("no error");
    break;
  case SPIFFSIniFile::errorFileNotFound:
    Serial.print("file not found");
    break;
  case SPIFFSIniFile::errorFileNotOpen:
    Serial.print("file not open");
    break;
  case SPIFFSIniFile::errorBufferTooSmall:
    Serial.print("buffer too small");
    break;
  case SPIFFSIniFile::errorSeekError:
    Serial.print("seek error");
    break;
  case SPIFFSIniFile::errorSectionNotFound:
    Serial.print("section not found");
    break;
  case SPIFFSIniFile::errorKeyNotFound:
    Serial.print("key not found");
    break;
  case SPIFFSIniFile::errorEndOfFile:
    Serial.print("end of file");
    break;
  case SPIFFSIniFile::errorUnknownError:
    Serial.print("unknown error");
    break;
  default:
    Serial.print("unknown error value");
    break;
  }
  if (eol)
    Serial.println();
}

void S3downloadFile(String url,String fileName){
    HTTPClient http;
    Serial.println(url);

    LogSPIFFS_Log("Downloading ");
    LogSPIFFS_Log(url);
    LogSPIFFS_Log(" ");
    LogSPIFFS_Log(fileName);
    LogSPIFFS_Log("   ");
   
    File f = SPIFFS.open(fileName, "w");
    if (f) {
      
      http.begin(url);
      int httpCode = http.GET();
      
      //Serial.printf("HTTP Code (%i) %s \n ",httpCode,http.errorToString(httpCode).c_str());
      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
          Serial.printf("[HTTP] GET... started, code: %s\n", http.errorToString(httpCode).c_str());
          http.writeToStream(&f);
          LogSPIFFS_Log("done");
          LogSPIFFS_Log("\n");
        }
      } else {
        LogSPIFFS_Log("[HTTP] GET failed");
        LogSPIFFS_Log("\n");
      }
      f.close();
      
    }
    http.end(); 
}


void S3getVersionFile(String familyName){
  String fileName = "/version.ini";
  String url = "http://steamclock.s3.eu-west-3.amazonaws.com/"+familyName+fileName;
  S3downloadFile(url,fileName);
}

int iniGetVersion(const char* filename){
  const size_t bufferLen = 80;
  char buffer[bufferLen];
  
  
  SPIFFSIniFile ini(filename);
  ini.open();
  
  if (ini.getValue("latest", "version", buffer, bufferLen)) {
    Serial.print("latest version from local inifile is ");
    Serial.println(buffer);
    return atoi(buffer);
  }
  else {
    Serial.print("Could not read latest version, error was ");
    printErrorMessage(ini.getError());
    Serial.print(" on filename");
    Serial.println(filename);
    return 0;
  }
  return true;  
}

void S3getDataFiles(String familyName,String iniVersion,const char* filename){
  const size_t bufferLen = 80;
  char buffer[bufferLen];
  

  if (iniVersion.length()==1) iniVersion = "00"+iniVersion;
  if (iniVersion.length()==2) iniVersion = "0"+iniVersion;
    
  LogSPIFFS_Log("Get DataFiles from ");
  LogSPIFFS_Log(filename);
  LogSPIFFS_Log("\n");
  
    
  SPIFFSIniFile ini(filename);
  ini.open();
  
  if (ini.getValue("files", "count", buffer, bufferLen)) {
    Serial.print("files count is ");
    Serial.println(buffer);
    int filesCount = atoi(buffer);
    char datatFilename [4];

    for (int file =0; file < filesCount; file++) {
      itoa(file,datatFilename,10);
      if (ini.getValue("files", datatFilename, buffer, bufferLen)) {
        Serial.print("\nfile # ");
        Serial.print(datatFilename);
        Serial.print(" is ");
        Serial.println(buffer);
        
        String dlfileName = "/"+String(buffer);
        String url = "http://steamclock.s3.eu-west-3.amazonaws.com/"+familyName+"/"+iniVersion+"/data"+dlfileName;
        S3downloadFile(url,dlfileName);
        
      }
    }
  }
  else {
    Serial.print("Could not read 'count' from section 'files', error was '");
    printErrorMessage(ini.getError());
    Serial.print("'\n");
    
  }
}

void S3updateBin(String familyName,String iniVersion){
  if (iniVersion.length()==1) iniVersion = "00"+iniVersion;
  if (iniVersion.length()==2) iniVersion = "0"+iniVersion;
  String url = "http://steamclock.s3.eu-west-3.amazonaws.com/"+familyName+"/"+iniVersion+"/bin/firmware.bin";
  
  LogSPIFFS_Log("Update bin file from ");
  LogSPIFFS_Log(url);
  
  t_httpUpdate_return ret = ESPhttpUpdate.update(url);
  switch(ret) {
    case HTTP_UPDATE_FAILED:
        LogSPIFFS_Log("\n[update] Update failed.\n");
        break;
    case HTTP_UPDATE_NO_UPDATES:
        LogSPIFFS_Log("\n[update] Update no Update.\n");
        break;
    case HTTP_UPDATE_OK:
        Serial.println("\n[update] Update ok."); // may not be called since we reboot the ESP
        break;
  }
}

void setupOTA(String familyName){
  const size_t bufferLen = 80;
  char buffer[bufferLen];
  const char *filename = "/version.ini";
  
  LogSPIFFS_Erase();
  
  printf(buffer,"Setup OTA for family %s \n",familyName.c_str());
  LogSPIFFS_Log(buffer);
  

  SPIFFSListing();
  bool loop = true;
  byte loopCount =0;
  int iniVersion;
  while (loop){
   
    S3getVersionFile(familyName);  
    iniVersion =iniGetVersion(filename); 


    if (iniVersion==1){
      S3getVersionFile(familyName); // get latest manifet 
      S3getDataFiles(familyName,String(iniVersion),filename); // get datafiles from manifest
      S3updateBin(familyName,String(iniVersion)); 
      
      ESP.restart();
      loop=false;
    } else {
    
    }

    
    delay (1000);
    SPIFFSListing();
    Serial.println("nope");
    loopCount++;
    if (loopCount>5) break;
   
  }

  /*
  SPIFFSIniFile ini(filename);
  if (!ini.open()) {
    Serial.print("Ini file ");
    Serial.print(filename);
    Serial.println(" does not exist");
    //downloadFile();// Cannot do anything else
    
  } else {
  
  Serial.println("Ini file exists");

  // Check the file is valid. This can be used to warn if any lines
  // are longer than the buffer.
  if (!ini.validate(buffer, bufferLen)) {
    Serial.print("ini file ");
    Serial.print(ini.getFilename());
    Serial.print(" not valid: ");
    printErrorMessage(ini.getError());
    // Cannot do anything else
    while (1)
      ;
  }
  
  // Fetch a value from a key which is present
  if (ini.getValue("latest", "version", buffer, bufferLen)) {
    Serial.print("latest version is ");
    Serial.println(buffer);
  }
  else {
    Serial.print("Could not read 'mac' from section 'network', error was ");
    printErrorMessage(ini.getError());
  }

    // Fetch a value from a key which is present
  if (ini.getValue("files", "count", buffer, bufferLen)) {
    Serial.print("files count is ");
    Serial.println(buffer);
  }
  else {
    Serial.print("Could not read 'mac' from section 'network', error was ");
    printErrorMessage(ini.getError());
  }

  int filesCount = atoi(buffer);
  char filename [4];

  for (int file =0; file < filesCount; file++) {
    
    itoa(file,filename,10);
    if (ini.getValue("files", filename, buffer, bufferLen)) {
      Serial.print("files ");
      Serial.print(filename);
      Serial.print(" is ");
      Serial.println(buffer);
    }
  }
*/
  
}
