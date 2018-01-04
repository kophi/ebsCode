#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

byte light[8];
uint8_t val = 3;

uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};

void printArray(){
  for(int i= 7; i>= 0; --i){
    lcd.setCursor(0, 0);
    lcd.createChar(0, duck);
    //lcd.write(byte(0));
    Serial.println(light[i]);
  }
  
  
 
}
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

int iVal= val;
for(int i=7; iVal >= 0; --i){
  --iVal;
  light[i]= 0b11111;
}

}

void loop() {
  delay(1000);
   printArray();

}
