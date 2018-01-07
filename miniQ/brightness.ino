char lcdVal[4];

void mBrightness() {
  if (modeChanged)
  {
    modeChanged = false;
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  }
  else if (currentKey == 3) { //standbybetrieb
    changeMode(M_STANDBY);
  }
  else {

    //showBrightness(500);

    if (currentMillis - previousMillis > 500) {
      //Serial.println("BRIGHTNESS_PRE: ");
      //Serial.println(millis());
      previousMillis = currentMillis;

      int brightVal = getBrightnessValue();
      sprintf(lcdVal, "%04d", brightVal);

      //playBeeep();

      lcd.home();
      lcd.print(lcdVal);
      //Serial.println("BRIGHTNESS_POST: ");
      //Serial.println(millis());
    }

    /*
      lcd.setCursor(0, 0);
      lcd.println("Follow the light ");
      lcd.setCursor(0, 1);
      lcd.println("Show the bright  ");
    */
  }
}

void showBrightness(int interval)
{
  if (currentMillis - previousMillis > interval) {
    //Serial.println("BRIGHTNESS_PRE: ");
    //Serial.println(millis());
    previousMillis = currentMillis;

    int brightVal = getBrightnessValue();
    sprintf(lcdVal, "%04d", brightVal);

    lcd.home();
    lcd.print(lcdVal);
    //Serial.println("BRIGHTNESS_POST: ");
    //Serial.println(millis());
  }
}

int getBrightnessValue()
{
  return analogRead(PIN_BRIGHTNESS);
}


