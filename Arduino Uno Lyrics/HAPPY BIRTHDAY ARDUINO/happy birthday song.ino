// Happy Birthday Song with Buzzer

int buzzer = 8; // Buzzer connected to pin 8

// Notes frequencies (Hz)
int notes[] = {
  262, 262, 294, 262, 349, 330,  // Happy birthday to you
  262, 262, 294, 262, 392, 349,  // Happy birthday to you
  262, 262, 523, 440, 349, 330, 294, // Happy birthday dear [Name]
  466, 466, 440, 349, 392, 349   // Happy birthday to you
};

// Duration of each note (ms)
int durations[] = {
  250, 250, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 1000
};

void setup() {
  for (int i = 0; i < 25; i++) {
    int duration = durations[i];
    tone(buzzer, notes[i], duration); // Play note
    delay(duration * 1.3);           // Pause between notes
    noTone(buzzer);                  // Stop sound
  }
}

void loop() {
  // Empty: runs once in setup()
}
