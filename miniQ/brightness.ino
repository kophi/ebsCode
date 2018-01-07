#define BRIGHTNESS_INTERVAL 500

unsigned long brightnessMillis = 0;
unsigned int brightnessValue;
char lcdValue[3];

int getBrightnessValue()
{
  return analogRead(PIN_BRIGHTNESS);
}

void mBrightness() {
  if (modeChanged)
  {
    modeChanged = false;
    
    lcd.print("Rel. brightness:");
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  }
  else if (currentKey == 3) {
    changeMode(M_STANDBY);
  }
  else {

    if (currentMillis - brightnessMillis > BRIGHTNESS_INTERVAL) {
      brightnessMillis = currentMillis;
      
      brightnessValue = map(getBrightnessValue(),0,1023,0,100);

      sprintf(lcdValue,"%03d", brightnessValue);

      lcd.setCursor(0, 1);
      lcd.print(lcdValue);
      lcd.print("%");
    }
  }
}




