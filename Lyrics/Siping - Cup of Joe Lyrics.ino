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

LyricLine lyrics[] = {
  {"Kahit isa lang",    "na saglit",       0},
  {"Kahit hindi na",    "maulit",          5},
  {"Oras ay labanan,",  "",                9},
  {"Ako'y iyong",       "samahang",       11},
  {"Sulitin bawat",     "sandali",        13},
  {"Dahil kahit isa",   "lang na saglit", 16},
  {"Kahit hindi na",    "maulit",         22},
  {"Ipadama ang init",  "ng yong yakap",  26},
  {"At dito sa aking",  "tabi",           29},
  {"Ikaw ay sumiping,", "ooh hoo...",     32}
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

    // Reset relative timer to 0
    unsigned long zeroTime = millis();

    for (int i = 0; i < lyricCount; i++) {
      unsigned long targetTime = lyrics[i].startSec * 1000;

      // Wait until it's time for the current lyric
      while ((millis() - zeroTime) < targetTime) {
        delay(10); // short delay to prevent freezing
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
