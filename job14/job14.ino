#include <LiquidCrystal_I2C.h>

int tick_clock;
int timer;
int buttonState;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(7, INPUT); //Button
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("B1 Logiciel G3");
  delay(50);
  tick_clock = HIGH;
  timer = 0;
}

void loop() {
  if (tick_clock == HIGH) {
    timer += 1;
    lcd.setCursor(0,1);
    lcd.print(timer);
    delay(1000);
  }
  buttonState = digitalRead(7);
  if (buttonState == HIGH && tick_clock == HIGH) {
    tick_clock = LOW;
    delay(100);
  }
  buttonState = digitalRead(7);
  if (buttonState == HIGH && tick_clock == LOW) {
    tick_clock = HIGH;
    delay(100);
  }
}