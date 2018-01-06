void mLineFollow() {        //fährt der Linie nach
  if (buttonPress == 1) {   //zurück ins menu
    mode = M_MENU;
    modeChanged = 1;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  else if (buttonPress == 3) { //standbybetrieb
    mode = M_STANDBY;
    playBeep(1, (3 - buttonPress) * 2.0, 10);
  }
  else {
    //code für Linefollowing
    lcd.setCursor(0, 0);
    lcd.println("Follow the light ");
    lcd.setCursor(0, 1);
    lcd.println("Walk the line   ");
  }
}
