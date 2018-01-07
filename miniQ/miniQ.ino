/***********************************************
   ebs HS 2017 Projekt
   miniQ Team 6
   Philipp Kopf
   Stephanie Fernandez Andersson
   Manuel Sutter
   Studiengang Systemtechnik 7.Semester
***********************************************
   Header
*/
#include <LiquidCrystal_I2C.h>

#define PIN_KEYS 6
#define PIN_BRIGHTNESS A5
#define PIN_SPEAKER 16

#define KEY_NONE 1020
#define KEY_1 200
#define KEY_2 620
#define KEY_3 760

#define M_STANDBY 0
#define M_MENU 1
#define M_LINEFOLLOW 2
#define M_BRIGHTNESS 3

#define DEBUG true


LiquidCrystal_I2C lcd(0x20, 16, 2);

unsigned int currentKey = 0;
unsigned int lastKey = 0;
unsigned int mode = M_STANDBY;
boolean modeChanged = true;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned int keyValue = 0;

void simpleBeep() {
  for (int i = 0; i < 30; i++) {
    digitalWrite(PIN_SPEAKER, HIGH);
    delay(2);
    digitalWrite(PIN_SPEAKER, LOW);
    delay(2);
  }
}

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
  simpleBeep();
}


/**************************************************
   Setup Routine
*/
void setup() {
  if (DEBUG)
  {
    Serial.begin(9600);
  }
  lcd.init();
  lcd.backlight();
}
/**************************************************
   Hauptschleife
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

  if (modeChanged)
  {
    lcd.clear();
  }
}
