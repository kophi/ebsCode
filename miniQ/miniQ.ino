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
#define button 6
#define analogKey1 150
#define analogKey2 600
#define analogKey3 750
#define analogNone 1020

#define M_STANDBY 0
#define M_MENU 1
#define M_LINEFOLLOW 2
#define M_BRIGHTNESS 3


LiquidCrystal_I2C lcd(0x20, 16, 2);

unsigned int buttonPress = 0;
int lastButton = 0;
int mode = M_STANDBY;
int modeChanged = 1;
long previousMillis = 0;
unsigned long currentMillis = 0;



/**************************************************
   Setup Routine
*/
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(16, OUTPUT);
}
/**************************************************
   Hauptschleife
*/
void loop() {
  detectButton();

  currentMillis = millis();

  if(modeChanged)
  {
    lcd.clear();
    Serial.println("CLEAR");
  }


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
