/***********************************************
   FHNW, ebs, HS17

   Stephanie Fernandez Andersson
   Philipp Kopf
   Manuel Sutter

   Modul: Brightness
***********************************************
*/

#define BRIGHTNESS_INTERVAL 240 // Interval mit dem der LCD-Text aktualisiert wird

unsigned long brightnessMillis = 0;
unsigned int brightnessValue;
byte brightnessPercent;
char lcdValue[3];

/**
 * liest den Analogwertwert des Sensors an PIN_BRIGHTNESS ein und gibt diesen
 * als Returnwert zurück
 */
int getBrightnessValue()
{
  return analogRead(PIN_BRIGHTNESS);
}

/**
 * Die Hauptfunktion für die Funktionsweise Licht Messen auf LCD anzeigen und
 * Tonhöhe entsprechend abspielen
 */
void mBrightness() {
  if (modeChanged)
  {
    modeChanged = false;

    lcd.print("Rel. brightness:");
    lcd.setCursor(3, 1);
    lcd.print("%");
  }
  else if (currentKey == 1) {
    changeMode(M_MENU);
  }
  else if (currentKey == 3) {
    changeMode(M_STANDBY);
  }
  else {

    brightnessValue = getBrightnessValue();

    beep(1023 - brightnessValue);

    if (currentMillis - brightnessMillis > BRIGHTNESS_INTERVAL) {
      brightnessMillis = currentMillis;

      brightnessPercent = map(brightnessValue, 0, 1023, 0, 100);

      sprintf(lcdValue, "%03d", brightnessPercent);

      lcd.setCursor(0, 1);
      lcd.print(lcdValue);
    }
  }
}
