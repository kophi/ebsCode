void mStandby()
{
  if (buttonPress == 1) {
    mode = M_MENU;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  if (modeChanged)
  {
    lcd.print("Standby");
    lcd.print("Press KEY1");
    modeChanged = 0;
    //lcd.noBacklight();
    playBeep(2, 1.0, 10);

  }
}
