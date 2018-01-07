#define BRIGHTNESS_INTERVAL 500

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

    if (currentMillis - previousMillis > BRIGHTNESS_INTERVAL) {
      previousMillis = currentMillis;
      
      int brightnessValue = getBrightnessValue();

      sprintf(lcdValue,"%03d", map(brightnessValue,0,1023,0,100));

      lcd.setCursor(0, 1);
      lcd.print(lcdValue);
      lcd.print("%");
    }
  }
}




