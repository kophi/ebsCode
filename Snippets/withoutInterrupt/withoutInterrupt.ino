#include <LiquidCrystal_I2C.h>
#define button 6
#define analKey1 150
#define analKey2 600
#define analKey3 750
#define analNone 1020
int buttPress;
int mode= 4;
int run;
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
 Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  
  
}
void detectButt(){
  if(analogRead(6)<analNone && buttPress==0){
  
  int analButt= analogRead(6);
  if(analButt<analKey1){
    buttPress= 1;
        //play beep1
  }
  else if(analButt< analKey2){
    buttPress= 2;
        //play beep2
  }
  else if(analButt<analKey3){
    buttPress= 3;
        //play beep3  
  }
 }
}

void mLineFollow(){
  if(buttPress==1){
    mode = 1;
  }
  
  
  else if(buttPress==3){
  mode= 4;
  }
  else{
    //code für Linefollowing
  }
}

void mMenu(){
  lcd.println("Choose Mode");
  if(buttPress==1){
 //LineFollow&Licht&LCD&Motors
 mode=0;
  }
  if(buttPress==2){
  //Licht&Ton&LCD
  }
  if(buttPress==3){
    //Menu beenden
 }
}

void mHell(){
  if(buttPress==1){
    mode = 1;
  }
}

void loop() {
detectButt(); 
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
  if(buttPress == 1){
    mode= 1;
  }
}


buttPress=0;
}
