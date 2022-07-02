//*********************************************************
void setupOLED()
{
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  Serial.print(u8x8.getCols());
  Serial.print(" x ");
  Serial.print(u8x8.getRows());
  
  u8x8.drawString(0,1,"Started");
}
