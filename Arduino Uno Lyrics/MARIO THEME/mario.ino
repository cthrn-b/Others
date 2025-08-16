// Super Mario Bros. Theme Song - Full Intro

int buzzer = 8;

// Mario main theme intro (expanded)
int melody[] = {
  660, 660, 660, 510, 660, 770, 380,  // ♪♫
  510, 380, 320, 440, 480, 450, 430,
  380, 660, 760, 860, 700, 760, 660,
  520, 580, 480, 510, 380, 320, 440,
  480, 450, 430, 380, 660, 760, 860,
  700, 760, 660, 520, 580, 480
};

// Durations (in ms)
int noteDurations[] = {
  100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 150, 150, 150, 150,
  300, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 150, 150, 150, 150,
  300, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 300, 300
};

int notes = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(buzzer, OUTPUT);

  // Play the Mario intro
  for (int i = 0; i < notes; i++) {
    int duration = noteDurations[i];
    if (melody[i] != 0) {
      tone(buzzer, melody[i], duration);
    }
    delay(duration * 1.3);
    noTone(buzzer);
  }
}

void loop() {
  // Empty – plays once
}
