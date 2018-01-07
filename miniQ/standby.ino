#define DISPLAY_TIMEOUT 6000

unsigned long standbyMillis = 0;

void mStandby()
{
  if (modeChanged)
  {
    modeChanged = false;

    lcd.print("Standby");
    lcd.setCursor(0, 1);
    lcd.print("Press KEY1");

    beep(2000);
    delay(10);
    beep(1500);
    delay(10);
    beep(1000);

    standbyMillis = millis();
  }
  else if (currentKey == 1) {
    lcd.backlight();
    changeMode(M_MENU);
  }
  else
  {
    if (millis() - standbyMillis > DISPLAY_TIMEOUT)
    {
      lcd.noBacklight();
    }
  }
}
