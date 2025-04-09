#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void smiley() {
  byte smiley[8] = {B00000, B10001, B00000, B00000, B10001, B01110, B00000,};
  lcd.createChar(0, smiley);
  lcd.setCursor(8, 0);
  lcd.write(0);
}

void setup()
{
  lcd.init();
  lcd.backlight();
  smiley();
}

void loop()
{
  
}