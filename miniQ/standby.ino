void mStandby()
{
  if (modeChanged)
  {
     modeChanged = false;
    
    lcd.print("Standby");
    lcd.print("Press KEY1");
    //lcd.noBacklight();
    beep(2000);
    delay(10);
    beep(1500);
    delay(10);
    beep(1000);
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  } 
}
