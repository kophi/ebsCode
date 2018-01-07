void mStandby()
{
  if (modeChanged)
  {
     modeChanged = false;
    
    lcd.print("Standby");
    lcd.print("Press KEY1");
    //lcd.noBacklight();
    simpleBeep();
    delay(10);
    simpleBeep();
    delay(10);
    simpleBeep();
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  } 
}
