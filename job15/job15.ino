// C++ code
//

int greenPin = 7;
int bluePin = 6;
int redPin= 5;

int Pot;
int greenVal;

void setup()
{
  pinMode(greenPin, OUTPUT); //Green
  pinMode(bluePin, OUTPUT); //Blue
  pinMode(redPin, OUTPUT); //Red
}

void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}

void loop()
{
  Pot = analogRead(A0);
  Serial.println(Pot);
  greenVal = map(Pot, 0, 1023, 0, 255);
  setColor(150, greenVal, 50);
}