/***********************************************
   FHNW, ebs, HS17

   Stephanie Fernandez Andersson
   Philipp Kopf
   Manuel Sutter

   Modul: System
***********************************************
*/

/**
 * Includes
 */
#include <LiquidCrystal_I2C.h>

/**
 * Pins
 */
#define PIN_KEYS 6
#define PIN_BRIGHTNESS A5
#define PIN_SPEAKER 16

/**
 * Tasten-Frequenzen
 */
#define KEY_NONE 1020
#define KEY_1 200
#define KEY_2 650
#define KEY_3 760

/**
 * Modi
 */
#define M_STANDBY 0
#define M_MENU 1
#define M_LINEFOLLOW 2
#define M_BRIGHTNESS 3

/**
 * Debug On/Off
 */
#define DEBUG false

/**
 * Variabeln deklarieren und initialisieren
 */
LiquidCrystal_I2C lcd(0x20, 16, 2);

byte currentKey = 0; //die aktuell gedrückte Taste
byte lastKey = 0; //die zuvor gedrückte Taste
byte mode = M_STANDBY; //der aktuelle Modus
boolean modeChanged = true; //damit erkennen die Module, dass der Modus gewechselt wurde
unsigned long currentMillis = 0; //aktuelle millis(). Für Timing
unsigned long startMillis = 0; //millis()-Zwischenspeicher für beep()
unsigned int keyValue = 0; //Zwischenspeicher für Tasten-Frequenz




/**
 * beep() erzeugt einen Ton über 100ms mit variabler Frequenz
 */
void beep(int freq)
{
  startMillis = currentMillis;
  do
  {
    digitalWrite(PIN_SPEAKER, HIGH);
    delayMicroseconds(freq);
    digitalWrite(PIN_SPEAKER, LOW);
    delayMicroseconds(freq);
  }
  while (millis() - startMillis < 100);
}

/**
 * simpleBeep() nutzt beep() um den Tastenton zu erzeugen
 */
void simpleBeep() {
  beep(1000);
}

/**
 * detectKeypress() erkennt ob und was für eine Taste gedrückt wurde.
 * Verhindert, dass die Taste mehrmals anschlägt wenn sie zuvor nicht losgelassen wurde
 */
void detectKeyPress() {         //erkennt welcher Key (1-3) gedrückt worden ist
  if (analogRead(PIN_KEYS) < KEY_NONE) {

    keyValue = analogRead(PIN_KEYS);

    if (keyValue < KEY_1) {
      currentKey = 1;
    }
    else if (keyValue < KEY_2) {
      currentKey = 2;
    }
    else if (keyValue < KEY_3) {
      currentKey = 3;
      
    }
    else {
      currentKey = 0;
    }
  }

  if (currentKey == lastKey)
  {
    currentKey = 0;
  }

  else
  {
    if (DEBUG && currentKey != 0)
    {
      Serial.print("Key press detected: ");
      Serial.println(currentKey);
    }

    lastKey = currentKey;
  }
}

/**
 * changeMode() ändert den Zusand auf den gewünschten Modus
 */
void changeMode(int newMode)
{
  if (DEBUG)
  {
    Serial.print("changeMode: ");
    Serial.print(mode);
    Serial.print(" -> ");
    Serial.println(newMode);
  }

  mode = newMode;
  modeChanged = true;
  lcd.clear();
  simpleBeep();
}


/**
 * setup() wird einmal ausgeführt wenn der MiniQ eingeschaltet wird
 */
void setup() {
  if (DEBUG)
  {
    Serial.begin(9600);
  }
  lcd.init();
  lcd.backlight();
}

/**
 * loop() ist die Hauptschleife und wird immer wieder ausgeführt.
 * Hier wird die Modus-Funktion des aktuellen Modus aufgerufen
 */
void loop() {

  detectKeyPress();

  currentMillis = millis();

  if (mode == M_LINEFOLLOW) { //Mode: LineFollow
    mLineFollow();
  }
  else if (mode == M_BRIGHTNESS) { //Mode: Brightness
    mBrightness();
  }
  else if (mode == M_MENU) { //Mode: Menu
    mMenu();
  }
  else { //Mode: Standby(Default Mode)
    mStandby();
  }
}
