
String padListing(String FileName, int expLength){
 
 while(FileName.length()<expLength){
  FileName = FileName +" "; 
 }
 return FileName;
}

String SPIFFSListingWeb(){
  String retVal="<br>";
  
  Dir dir = SPIFFS.openDir("");
  
  while (dir.next()) {
    
    retVal+= dir.fileName();
    retVal+="&nbsp;&nbsp;";
    retVal+= String(dir.fileSize());
    retVal+="<BR>";
  }
  retVal+="<hr>";
  
  return retVal;
}


void SPIFFSListing(){
  Serial.print("\n\n");
  Serial.print("╔═════════════════════════╗\n");
  Serial.print("║   SPIFFS LISTING                          ║\n");
  Serial.print("╠═════════════════════════╣\n");
  
  String str = "";
  
  Dir dir = SPIFFS.openDir("");
  while (dir.next()) {
    Serial.print("║");
    Serial.print(padListing(dir.fileName(),30));
    Serial.print(" | ");
    Serial.print(padListing(String(dir.fileSize()),10));
    Serial.println("║");
  }
  Serial.print("╚═════════════════════════╝\n\n");
}

void formatSPIFFS(){
  Serial.print("Formatting SPIFFS ...");
  Serial.print(SPIFFS.format());
  Serial.println(".. done");  
}

void setupSPIFFS(){

  if (!SPIFFS.begin()) {
    Serial.println("Error mounting the file system");
    formatSPIFFS();
  } else {
    SPIFFSListing();
  }
}



void LogSPIFFS_Log(String toLog){

  Serial.print(toLog);
  String fileName = "/otalog.txt";
  File file;
  
  if (SPIFFS.exists(fileName)){
    file = SPIFFS.open(fileName,"a");
  } else {
    file = SPIFFS.open(fileName, "w+");
  }
  
  if (!file) {
    Serial.println("Error opening file for writing");
    return;
  }

  int bytesWritten = file.print(toLog);
 
  if (bytesWritten > 0) {

  } else {
    Serial.println("log write failed");
  }
 
  file.close();
}


String LogSPIFFS_Read(){
  String retVal="";
  String fileName = "/otalog.txt";

  Serial.println ("\n\n\n SPIFFS Log Read");
  
  File file = SPIFFS.open(fileName, "r");
  if (!file) {
    retVal = "Error opening file for reading";
    Serial.println(retVal);
    return retVal;
  }

  while(file.available()){
   char rdchar =file.read();
   //retVal = retVal +char(rdchar);
   
   if ((rdchar ==10)||(rdchar ==13))  {
      retVal = retVal + "<br>";
    }else {
       retVal = retVal + char(rdchar);
     //Serial.print(rdchar);
   }
    
  }
 
  file.close();
  Serial.println ("\n\ SPIFFS END  n");
  return retVal;
}


String LogSPIFFS_Erase(){
  String fileName = "/otalog.txt";
   SPIFFS.remove(fileName);
}
