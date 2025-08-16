// Looping Lullaby - Twinkle Twinkle Little Star

int buzzer = 8; // Buzzer pin

// Notes frequencies (Hz)
int melody[] = {
  262, 262, 392, 392, 440, 440, 392, // Twinkle twinkle little star
  349, 349, 330, 330, 294, 294, 262, // How I wonder what you are
  392, 392, 349, 349, 330, 330, 294, // Up above the world so high
  392, 392, 349, 349, 330, 330, 294, // Like a diamond in the sky
  262, 262, 392, 392, 440, 440, 392, // Twinkle twinkle little star
  349, 349, 330, 330, 294, 294, 262  // How I wonder what you are
};

// Durations: 4 = quarter note, 2 = half note, etc.
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void setup() {
}

void loop() {
  // Play the full melody
  for (int i = 0; i < 42; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(buzzer, melody[i], noteDuration);

    // Pause between notes
    int pause = noteDuration * 1.3;
    delay(pause);

    noTone(buzzer);
  }

  // Small pause before repeating
  delay(1000);
}
