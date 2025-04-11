#include <LiquidCrystal_I2C.h>

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

int sequenceLength = 2;
int randomSequence[50];
int randomNum;
int inputSequence[50];

int index;

LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
    pinMode(blueLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);

    pinMode(blueButton, INPUT);
    pinMode(redButton, INPUT);
    pinMode(greenButton, INPUT);
    pinMode(yellowButton, INPUT);

    lcd.init();
    lcd.backlight();
}

void loop() {
    lcd.setCursor(0,0);
    lcd.print("Niveau  ");
    lcd.print(sequenceLength - 1);
    generateSequence();
    index = 0;
    while (index < sequenceLength) {
        readInput();
    }

    if (checkSequence() == 1) { //Correct
        lcd.setCursor(0,0);
        lcd.print("Correct   ");
        light_blue();
        light_red();
        light_green();
        light_yellow();
        sequenceLength++;
    }

    if (checkSequence() == 0) { // Wrong
        lcd.setCursor(0,0);
        lcd.print("Game Over ");
        light_yellow();
        light_green();
        light_red();
        light_blue();
        sequenceLength = 2;
    }
}

void generateSequence() {
    int index = 0;
    for (int i = 0; i < sequenceLength; i++) {
        randomNum = rand() % 4;
        randomSequence[index] = ledList[randomNum];
        index++;
    }

    for (int i = 0; i < sequenceLength; i++) {
        digitalWrite(randomSequence[i], HIGH);
        delay(1000);
        digitalWrite(randomSequence[i], LOW);
        delay(400);
    }
}

void readInput() {
    for (int i = 0; i < 4; i++) {
        if (digitalRead(buttonList[i]) == LOW) {
            digitalWrite(ledList[i], HIGH);
            delay(500);
            digitalWrite(ledList[i], LOW);
            delay(200);
            inputSequence[index] = ledList[i];
            index++;
        }
    }
}

int checkSequence() {
    for (int i = 0; i < sequenceLength; i++) {
        if (randomSequence[i] != inputSequence[i]) {
            return 0;
        }
    }
    return 1;
}



// Turn on each LEDs

void light_blue() {
    digitalWrite(blueLed, HIGH);
    delay(500);
    digitalWrite(blueLed, LOW);
    delay(400);
}

void light_red() {
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
    delay(400);
}

void light_green() {
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(400);
}

void light_yellow() {
    digitalWrite(yellowLed, HIGH);
    delay(500);
    digitalWrite(yellowLed, LOW);
    delay(400);
}