int blueLed = 7;
int redLed = 6;
int greenLed = 5;
int yellowLed = 4;

int blueButton = 13;
int redButton = 12;
int greenButton = 11;
int yellowButton = 10;

int buttonList[4] = {blueButton, redButton, greenButton, yellowButton};
int ledList[4] = {blueLed, redLed, greenLed, yellowLed};



void setup() {
    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);

    pinMode(blueButton, INPUT);
    pinMode(redButton, INPUT);
    pinMode(greenButton, INPUT);
    pinMode(yellowButton, INPUT);
}

void loop() {
    for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonList[i]) == HIGH) {
            digitalWrite(ledList[i], HIGH);
            delay(500);
            digitalWrite(ledList[i], LOW);
        }
    }
}



// Turn on each LEDs

void light_blue() {
    digitalWrite(blueLed, HIGH);
    delay(1000);
    digitalWrite(blueLed, LOW);
}

void light_red() {
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
}

void light_green() {
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, LOW);
}

void light_yellow() {
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed, LOW);
}