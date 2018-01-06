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
int buttonPress = 0;
int lastButton = 0;
int mode= 3;
int modeChanged = 1;

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
              //Zeit zum loslassen des Tasters
  }
  else if(analogButton< analogKey2){
    buttonPress= 2;
        //play beep2
              //Zeit zum loslassen des Tasters
  }
  else if(analogButton<analogKey3){
    buttonPress= 3;
        //play beep3
              //Zeit zum loslassen des Tasters  
  }
 }
 if(buttonPress == lastButton)
 {
  buttonPress = 0;
 }
 else
 {
  lastButton = buttonPress;
 }
}
//--------------------------------------------------
void mLineFollow(){         //fährt der Linie nach
  if(buttonPress==1){       //zurück ins menu
    mode = 1;
    modeChanged=1;
  }
  else if(buttonPress==3){  //standbybetrieb
  mode= 3;
  }
  else{
    //code für Linefollowing
    lcd.setCursor(0,0);
    lcd.println("Follow the light ");
    lcd.setCursor(0,1);
    lcd.println("Walk the line   ");
  }
}
//---------------------------------------------------
void mMenu(){             //startet das Menu zeigt es auf dem LCD an
  lcd.setCursor(0,0);
  lcd.println("Choose Mode     ");
  lcd.setCursor(0,1);
  lcd.println("Press KEY 1/2/3 ");
  if(buttonPress==1){     //LineFollow&Licht&LCD&Motors
    mode=0;
    modeChanged=1;
  }
  if(buttonPress==2){     //Licht&Ton&LCD
    mode=2;
    modeChanged=1;
  }
  if(buttonPress==3){     //Menu beenden -->Standbybetrieb
    lcd.clear();
    mode= 3;
    modeChanged=1;
 }
 
}
//---------------------------------------------------
void mHell(){             //misst die Helligkeit, zeigt diese auf dem LCD an
  if(buttonPress==1){
    mode = 1;
    modeChanged=1;
  }
  else if(buttonPress==3){  //standbybetrieb
    mode= 3;
    modeChanged=1;
  }
  else{
  lcd.setCursor(0,0);
  lcd.println("Follow the light ");
  lcd.setCursor(0,1);
  lcd.println("Show the bright  ");
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
  
/**************************************************
 * Hauptschleife
*/  
}
void loop() {
detectButton(); 
Serial.print("buttonPress :");
Serial.println(buttonPress);
Serial.print("mode:        ");
Serial.println(mode);

//delay(1000); //nur für Serial Monitor auslesung!!
if (mode == 0){//LineFollow
  mLineFollow();
  
 }
 else if (mode == 1){//menuMode
  
    //Zeit zum loslassen des Tasters
  mMenu();
  
 }
else if (mode == 2){//Helligkeit
    mHell();
}
else if(mode == 3){//Standby
  if(buttonPress == 1){
    mode= 1;
  }
  if(modeChanged)
  {
    lcd.clear();
    lcd.println("Standby         ");
    modeChanged = 0;
    
  }
}



}
