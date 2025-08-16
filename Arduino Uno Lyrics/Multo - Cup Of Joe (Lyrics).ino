#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;
bool songStarted = false;

struct LyricLine {
  const char* line1;
  const char* line2;
  int startSec; // time in seconds from start
};

// --- Multo (Cup of Joe) ---
LyricLine lyrics[] = {
  {"Hindi na makalaya", "",                   0},
  {"Dinadalaw mo 'ko",  "bawat gabi",         5},
  {"Wala mang",         "nakikita",           10},
  {"Haplos mo'y ramdam", "pa rin sa dilim",   14},
  {"Hindi na",          "nananaginip",        20},
  {"Hindi na",          "ma-makagising",      24},
  {"Pasindi na ng", "ilaw",                  28},
  {"Minumulto na 'ko",  "ng damdamin ko",     32},
  {"Ng damdamin ko",    "",                   37},
  {"'Di mo ba ako",     "lilisanin?",         41},
  {"Hindi pa ba sapat", "pagpapahirap sa 'kin?", 46},
  {"(Damdamin ko)",     "",                   52},
  {"Hindi na ba",       "ma-mamamayapa?",     56},
  {"Hindi na ba",       "ma-mamamayapa?",     61}
};

const int lyricCount = sizeof(lyrics) / sizeof(lyrics[0]);

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Press button to");
  lcd.setCursor(0, 1);
  lcd.print("start lyrics...");
}

void loop() {
  if (!songStarted && digitalRead(buttonPin) == LOW) {
    songStarted = true;

    // Countdown for syncing
    lcd.clear();
    for (int i = 3; i > 0; i--) {
      lcd.setCursor(0, 0);
      lcd.print("Starting in...");
      lcd.setCursor(0, 1);
      lcd.print(i);
      delay(1000);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Playing lyrics...");
    delay(1000);
    lcd.clear();

    // Reset timer
    unsigned long zeroTime = millis();

    for (int i = 0; i < lyricCount; i++) {
      unsigned long targetTime = lyrics[i].startSec * 1000;

      while ((millis() - zeroTime) < targetTime) {
        delay(10);
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(lyrics[i].line1);
      lcd.setCursor(0, 1);
      lcd.print(lyrics[i].line2);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lyrics finished.");
    delay(10000);
  }
}
