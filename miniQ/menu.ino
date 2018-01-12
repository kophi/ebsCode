/***********************************************
   FHNW, ebs, HS17

   Stephanie Fernandez Andersson
   Philipp Kopf
   Manuel Sutter

   Modul: Menu
***********************************************
*/

void mMenu() {

  if (modeChanged)
  {
    modeChanged = 0;

    lcd.setCursor(0, 0);
    lcd.print("Choose Mode");
    lcd.setCursor(0, 1);
    lcd.print("Press KEY 1/2/3 ");
  }
  else if (currentKey == 1) { //LineFollow
    changeMode(M_LINEFOLLOW);
  }
  else if (currentKey == 2) { //Brightness
    changeMode(M_BRIGHTNESS);
  }
  else if (currentKey == 3) { //Standby
    changeMode(M_STANDBY);
  }
}
