int Pot;
int value_led_1;
int value_led_2;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); //LED 1
  pinMode(10, OUTPUT); //LED 2
}

void loop() {
  Pot = analogRead(A1); 
  value_led_1 = map(Pot, 0, 1023, 0, 255);
  value_led_2 = 255 - value_led_1;
  analogWrite(9, value_led_1);
  analogWrite(10, value_led_2);
  delay(200);
}