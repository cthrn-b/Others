// Tetris Theme (Korobeiniki)

int buzzer = 8;

// Melody (Tetris main theme)
int melody[] = {
  659, 494, 523, 587, 523, 494, 440, 
  440, 523, 659, 587, 523, 494, 523, 587, 
  659, 523, 440, 440, 0,

  587, 698, 880, 784, 698, 659, 523, 
  659, 587, 523, 494, 494, 523, 587, 
  659, 523, 440, 440, 0
};

// Note durations (ms)
int noteDurations[] = {
  250, 125, 125, 250, 125, 125, 250,
  125, 125, 250, 125, 125, 250, 125, 125,
  250, 250, 250, 250, 250,

  250, 125, 125, 250, 125, 125, 250,
  125, 125, 250, 125, 125, 250, 125, 125,
  250, 250, 250, 250, 250
};

int notes = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < notes; i++) {
    int duration = noteDurations[i];
    if (melody[i] != 0) {
      tone(buzzer, melody[i], duration);
    }
    delay(duration * 1.3);
    noTone(buzzer);
  }

  delay(1500); // pause before repeating
}
