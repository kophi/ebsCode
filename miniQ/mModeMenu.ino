void mMenu() {            //startet das Menu zeigt es auf dem LCD an
  lcd.setCursor(0, 0);
  lcd.print("Choose Mode");
  lcd.setCursor(0, 1);
  lcd.print("Press KEY 1/2/3 ");
  if (buttonPress == 1) { //LineFollow&Licht&LCD&Motors
    mode = M_LINEFOLLOW;
    modeChanged = 1;
    //playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  if (buttonPress == 2) { //Licht&Ton&LCD
    mode = M_BRIGHTNESS;
    modeChanged = 1;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  if (buttonPress == 3) { //Menu beenden -->Standbybetrieb
    mode = M_STANDBY;
    modeChanged = 1;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
}
