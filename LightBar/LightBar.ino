#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

byte light[9];
uint8_t val = 3;

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.createChar(0, smiley);
  lcd.write(smiley);
    
  
}

void loop() {
  //lcd.println("smiley");
  }

