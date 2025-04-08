#include <Arduino.h>
#include <OneButton.h>

#define BUTTON_PIN 2

int buttonState = 0;
int ledState = 0;
OneButton button(2, true);


void setup() {
  Serial.begin(9600)

  button.attachClick(singleClick);
  button.attachDoubleClick(doubleClick);
  button.attachLongPressStart(longPressStart);
  button.attachLongPressStop(longPressStop);

  pinMode(3, OUTPUT); // Led
  pinMode(2, INPUT); //Button
}

void loop() {
  button.tick();
  delay(10);
}

void singleClick() {
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);
}

void doubleClick() {
  digitalWrite(3, HIGH);
}

void 