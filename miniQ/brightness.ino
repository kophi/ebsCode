#define BRIGHTNESS_INTERVAL 500

unsigned long brightnessMillis = 0;
unsigned int brightnessValue;
byte brightnessPercent;
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
    lcd.setCursor(3, 1);
    lcd.print("%");
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  }
  else if (currentKey == 3) {
    changeMode(M_STANDBY);
  }
  else {

    brightnessValue = getBrightnessValue();

    beep(1023 - brightnessValue);

    if (currentMillis - brightnessMillis > BRIGHTNESS_INTERVAL) {
      brightnessMillis = currentMillis;

      brightnessPercent = map(brightnessValue, 0, 1023, 0, 100);

      sprintf(lcdValue, "%03d", brightnessPercent);

      lcd.setCursor(0, 1);
      lcd.print(lcdValue);
    }
  }
}
