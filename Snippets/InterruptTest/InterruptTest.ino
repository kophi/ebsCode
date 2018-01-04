#include <LiquidCrystal_I2C.h>
volatile unsigned long alteZeit=0, entprellZeit=20;
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  pinMode(6, INPUT);       // Pin 1 ist INT2
  digitalWrite(6, LOW);   // interner Pull up Widerstand auf 5V
  attachInterrupt(digitalPinToInterrupt(6), interruptRoutine, HIGH);
  // Pin 1 (INT 3) geht auf 0V (LOW) dann interruptRoutine aufrufen

}

void loop() {
  Serial.println(analogRead(6));
}

void interruptRoutine() {
  Serial.println("Interrupt");
  if((millis() - alteZeit) > entprellZeit) { 
    // innerhalb der entprellZeit nichts machen
lcd.print(" Menu1");
    alteZeit = millis(); // letzte Schaltzeit merken      
  }
}
