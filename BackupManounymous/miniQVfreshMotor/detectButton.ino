void detectButton() {         //erkennt welcher Key (1-3) gedrückt worden ist
  if (analogRead(6) < analogNone && buttonPress == 0) {

    int analogButton = analogRead(6);
    if (analogButton < analogKey1) {
      buttonPress = 1;
    }
    else if (analogButton < analogKey2) {
      buttonPress = 2;
    }
    else if (analogButton < analogKey3) {
      buttonPress = 3;
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
