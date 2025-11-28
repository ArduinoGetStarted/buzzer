/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/library/arduino-melody-repeat-example
   Library References: https://arduinogetstarted.com/tutorials/arduino-buzzer-library

   This example uses a piezo buzzer:
   + play a melody on background
   + repeat the melody when it is ended
   + without using delay() function, this is a non-blocking example
*/

#include <ezBuzzer.h> // ezBuzzer library

const int BUZZER_PIN = 3;

ezBuzzer buzzer(BUZZER_PIN, BUZZER_TYPE_PASSIVE, HIGH); // create ezBuzzer object: pin, type, activeLevel (PASSIVE for melody)

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

int noteLength;

void setup() {
  Serial.begin(9600);
  noteLength = sizeof(noteDurations) / sizeof(int);
}

void loop() {
  buzzer.loop(); // MUST call the buzzer.loop() function in loop()

  if (buzzer.getState() == BUZZER_IDLE) { // if stopped
    buzzer.playMelody(melody, noteDurations, noteLength); // playing
  }
}