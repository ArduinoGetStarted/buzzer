/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/library/arduino-melody-example
   Library References: https://arduinogetstarted.com/tutorials/arduino-buzzer-library

   This example uses a piezo buzzer:
   + plays a melody once on background each time a button is pressed
   + stops playing a melody when another button is pressed
   + without using delay() function, this is a non-blocking example
*/

#include <ezBuzzer.h> // ezBuzzer library

const int START_BUTTON_PIN = 7;
const int STOP_BUTTON_PIN  = 8;
const int BUZZER_PIN = 3;

int lastStartButtonState = HIGH; // the previous state from the input pin
int lastStopButtonState  = HIGH; // the previous state from the input pin

ezBuzzer buzzer(BUZZER_PIN); // create ezBuzzer object that attach to a pin;

// notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(START_BUTTON_PIN, INPUT_PULLUP);
  pinMode(STOP_BUTTON_PIN,  INPUT_PULLUP);
}

void loop() {
  buzzer.loop(); // MUST call the buzzer.loop() function in loop()

  int startButtonState = digitalRead(START_BUTTON_PIN);
  int stopButtonState  = digitalRead(STOP_BUTTON_PIN);

  if (lastStartButtonState == HIGH && startButtonState == LOW) {
    Serial.println("The START button is pressed");
    if (buzzer.getState() == BUZZER_IDLE) {
      int length = sizeof(noteDurations) / sizeof(int);
      buzzer.playMelody(melody, noteDurations, length); // playing
    }
  }

  if (lastStopButtonState == HIGH && stopButtonState == LOW) {
    Serial.println("The STOP button is pressed");
    if (buzzer.getState() != BUZZER_IDLE) {
      buzzer.stop() ; // stop
    }
  }

  lastStartButtonState = startButtonState;
  lastStopButtonState  = stopButtonState;
}