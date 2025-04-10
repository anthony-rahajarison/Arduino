#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sec;
int min;
int hour;

void setup() {
  lcd.init();
  lcd.backlight();
  set_clock(2, 58, 55);
}

void loop() {
  delay(1000);
  tick_clock();
  print_clock();
}

void set_clock(int h, int m, int s) {
  sec = s;
  min = m;
  hour = h;
}

void tick_clock() {
  sec ++;
  if (sec == 60) {
    sec = 0;
    min++;
  }

  if (min == 60) {
    min = 0;
    hour++;
  }

  if (hour == 24) {
    hour = 0;
  }
}

void print_clock() {
  lcd.setCursor(0,0);

  if (hour < 10) {lcd.print("0");}
  lcd.print(hour);
  lcd.print(":");

  if (min < 10) {lcd.print("0");}
  lcd.print(min);
  lcd.print(":");

  if (sec < 10) {lcd.print("0");}
  lcd.print(sec);
}