void mMenu() {            //startet das Menu zeigt es auf dem LCD an

  if (modeChanged)
  {
    modeChanged = 0;

    lcd.setCursor(0, 0);
    lcd.print("Choose Mode");
    lcd.setCursor(0, 1);
    lcd.print("Press KEY 1/2/3 ");
  }
  else if (currentKey == 1) { //LineFollow&Licht&LCD&Motors
    changeMode(M_LINEFOLLOW);
  }
  else if (currentKey == 2) { //Licht&Ton&LCD
    changeMode(M_BRIGHTNESS);
  }
  else if (currentKey == 3) { //Menu beenden -->Standbybetrieb
    changeMode(M_STANDBY);
  }
}
