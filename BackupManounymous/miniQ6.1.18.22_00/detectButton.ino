void detectButton() {         //erkennt welcher Key (1-3) gedrückt worden ist
  if (analogRead(6) < analogNone && buttonPress == 0) {

    int analogButton = analogRead(6);
    if (analogButton < analogKey1) {
      buttonPress = 1;
      simpleBeep();
    }
    else if (analogButton < analogKey2) {
      buttonPress = 2;
       simpleBeep();
    }
    else if (analogButton < analogKey3) {
      buttonPress = 3;
      simpleBeep();
    }
  }
  if (buttonPress == lastButton)
  {
    buttonPress = 0;
   
  }
  else
  {
    lastButton = buttonPress;

  }
}
