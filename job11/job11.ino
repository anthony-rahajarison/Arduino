int buttonState;
int fanState;

void setup() {
  pinMode(7, INPUT); //Button
  pinMode(8, OUTPUT); //LED
  pinMode(9, OUTPUT); //Fan
  fanState = LOW;
}

void loop() {
  buttonState = digitalRead(7);
  if (buttonState == HIGH && fanState == LOW) {
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    fanState = HIGH;
    digitalWrite(9, HIGH);
  }
  buttonState = digitalRead(7);
  if (buttonState == HIGH && fanState == HIGH) {
    digitalWrite(9, LOW);
    fanState = LOW;
    delay(1000);
  }
}