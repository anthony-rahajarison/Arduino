void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 2; i < 10; i++) {
    if(i == 2) {
    	digitalWrite(9, LOW);
    }
    digitalWrite(i-1, LOW);
    digitalWrite(i, HIGH);
    delay(1000);
  }
}
