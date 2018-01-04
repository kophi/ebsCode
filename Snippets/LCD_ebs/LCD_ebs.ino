//Test LCD Manuel Sutter
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1 ,0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = { 0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};
uint8_t lineRight[8] =  {0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1, 0b1};
uint8_t lineLeft[8] =   {0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000};
uint8_t lineLow[8] =   {0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b11111};
uint8_t lineUp[8] =     {0b11111, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
//uint8_t lineUp[8] =     {0b11111, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
//uint8_t lineUp[8] =     {0b11111, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0, 0b0};
byte light[8];
uint8_t val = 3;


/*for (int i = 7; i>=(8-num); --i)
{
  blubb[i] = 0b11111;
}

for (int i = num; i>=0; --i)
{
  blubb[i] = 0b0;
}
*/
void printArray(){
  for(int i= 7; i>= 0; --i){
    lcd.setCursor(0, 0);
    lcd.createChar(0, light[i]);
    lcd.write(byte(0));
  }
  
  
  lcd.setCursor(14, 0);
  lcd.write(9);
  lcd.setCursor(13, 1);
  lcd.write(8);
  lcd.setCursor(14, 1);
  lcd.write(9);
}
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, clock);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);
  lcd.createChar(8, lineRight);
  lcd.createChar(9, lineLeft);
  lcd.createChar(10, lineLow);
  lcd.home();


int iVal= val;
for(int i=7; iVal >= 0; --i){
  --iVal;
  light[i]= 0b11111;
}
 

  /*lcd.setCursor(13, 0);
  lcd.write(8);
  lcd.setCursor(14, 0);
  lcd.write(9);
  lcd.setCursor(13, 1);
  lcd.write(8);
  lcd.setCursor(14, 1);
  lcd.write(9);
  */
  //lcd.print("Hello world...");
  //lcd.setCursor(0, 1);
  //lcd.print(" I ");
  //lcd.write(3);
  //lcd.print(" arduinos!");
  


}

void loop() {
  // put your main code here, to run repeatedly:

}
