#include <toneAC.h>

const int buttonPin1 = 2; // Connect the first button to pin 2
const int buttonPin2 = 3; // Connect the second button to pin 3
const int buttonPin3 = 4; // Connect the third button to pin 4
const int buzzerPin = 8;  // Connect the buzzer to pin 8

// Define note constants manually
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_D1 37
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_G1 49
#define NOTE_A1 55
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_D2 73
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_G2 98
#define NOTE_A2 110
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_D6 1175
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_D7 2349
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_G7 3136
#define NOTE_A7 3520
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_D8 4699
#define NOTE_REST 0

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {
    playChristmasInOurHearts();
  } else if (digitalRead(buttonPin2) == LOW) {
    playAllIWantForChristmasIsYou();
  } else if (digitalRead(buttonPin3) == LOW) {
    playWeWishYouAMerryChristmas();
  }
}

// Rest of the code remains the same...


void playMelody(const int melody[], const int noteDurations[], int melodyLength) {
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    toneAC(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}

void playChristmasInOurHearts() {
  int melody[] = {
    NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
  };

  int noteDurations[] = {
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 2, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4
  };

  int melodyLength = sizeof(melody) / sizeof(melody[0]);
  playMelody(melody, noteDurations, melodyLength);
}

void playAllIWantForChristmasIsYou() {
  int melody[] = {
    NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_A5, NOTE_G5,
    NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
    NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_A5, NOTE_G5,
    NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
    NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5,
    NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_G4
  };

  int noteDurations[] = {
    4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 2, 2,
    4, 4, 4, 4, 4
  };

  int melodyLength = sizeof(melody) / sizeof(melody[0]);
  playMelody(melody, noteDurations, melodyLength);
}

void playWeWishYouAMerryChristmas() {
  int melody[] = {
    NOTE_A4, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4,
    NOTE_C5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4,
    NOTE_A4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4,
    NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4
  };

  int noteDurations[] = {
    4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 2
  };

  int melodyLength = sizeof(melody) / sizeof(melody[0]);
  playMelody(melody, noteDurations, melodyLength);
}
