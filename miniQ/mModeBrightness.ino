void mBrightness() {            //misst die Helligkeit, zeigt diese auf dem LCD an
  if (buttonPress == 1) {
    mode = M_MENU;
    modeChanged = 1;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  else if (buttonPress == 3) { //standbybetrieb
    mode = M_STANDBY;
    modeChanged = 1;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  else {
    
    if (currentMillis - previousMillis > 500) {
      //Serial.println("BRIGHTNESS_PRE: ");
      //Serial.println(millis());
      previousMillis = currentMillis;

      int brightVal = getBrightnessValue();
      char lcdVal[6];
      sprintf(lcdVal, "%04d",brightVal);
  
      
      //lcd.clear();
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
