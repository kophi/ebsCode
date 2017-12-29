/***********************************************
 * ebs HS 2017 Projekt
 * miniQ Team 6
 * Philipp Kopf
 * Stephanie Fernandez Andersson
 * Manuel Sutter
 * Studiengang Systemtechnik 7.Semester
***********************************************
 * Header
*/
#include <LiquidCrystal_I2C.h>
#define button 6
#define analogKey1 150
#define analogKey2 600
#define analogKey3 750
#define analogNone 1020
int buttonPress;
int mode= 4;
int run;
LiquidCrystal_I2C lcd(0x20, 16, 2);
/***********************************************
 * Functions
*/
void detectButton(){          //erkennt welcher Key (1-3) gedrückt worden ist
  if(analogRead(6)<analogNone && buttonPress==0){
  
  int analogButton= analogRead(6);
  if(analogButton<analogKey1){
    buttonPress= 1;
        //play beep1
  }
  else if(analogButton< analogKey2){
    buttonPress= 2;
        //play beep2
  }
  else if(analogButton<analogKey3){
    buttonPress= 3;
        //play beep3  
  }
 }
}
//--------------------------------------------------
void mLineFollow(){         //fährt der Linie nach
  if(buttonPress==1){
    mode = 1;
  }
  else if(buttonPress==3){
  mode= 4;
  }
  else{
    //code für Linefollowing
  }
}
//---------------------------------------------------
void mMenu(){             //startet das Menu zeigt es auf dem LCD an
  lcd.println("Choose Mode");
  if(buttonPress==1){
 //LineFollow&Licht&LCD&Motors
 mode=0;
  }
  if(buttonPress==2){
  //Licht&Ton&LCD
  }
  if(buttonPress==3){
    //Menu beenden
 }
}
//---------------------------------------------------
void mHell(){           //misst die Helligkeit, zeigt diese auf dem LCD an
  if(buttonPress==1){
    mode = 1;
  }
}
//---------------------------------------------------
/**************************************************
 * Setup Routine
*/
void setup() {
 Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
/**************************************************
 * Hauptschleife
*/  
}
void loop() {
detectButton(); 
Serial.println(mode);


if (mode == 0){//LineFollow
  mLineFollow();
  
 }
 else if (mode == 1){//menuMode
  mMenu();
  
 }
else if (mode == 2){//Helligkeit
    mHell();
}
else if(mode == 3){//Standby
  if(buttonPress == 1){
    mode= 1;
  }
}


buttonPress=0;
}
