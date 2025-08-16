#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;
bool songStarted = false;

struct LyricLine {
  const char* line1;
  const char* line2;
  int startSec; // time in seconds from song start
};

LyricLine lyrics[] = {
  {"La-la-la-la, la", "La-la-la-la, la",          0},
  {"Minsan, gusto kong", "magsumbong sa'yo",        15},
  {"Kapag pagod na", "pagod na ako",               21},
  {"Tama pa bang", "init ng yakap mo",           26},
  {"Ang hinahanap ko...",  "",                     34},
  {"Minsan, gusto kong", "tumawag sa'yo",           38},
  {"Para lang marinig", "ko ang boses mo",         45},
  {"Mali na ba kapag", "nakangiti ako?",           55},
  {"Hinahanap ko", "ang sa'yo",                    64},
  {"Kahit hindi na", "kita nakikita, ah",           95},
  {"Kahit lumipas man", "ilang dekada, ah",        105},
  {"Kahit nagbago na", "hinahanap ng 'yong mga mata", 115},
  {"Hanggang may kahel", "na langit, maiisip kita", 125},
  {"Kamukha ng pagsibol", "ng araw",               140},
  {"Mukha mong 'di na", "abot-tanaw",              150},
  {"Sa dami ng sukat", "ng kamay at daliring",     160},
  {"Sa'yo lang 'di", "napapasma, perpektong akma", 170},
  {"Sa mga araw na", "wala akong kakampi",        185},
  {"Sa tuwing may", "luha sa ngiti ko",            195},
  {"Sa umpisa ng araw", "at bago mag gabi",         205},
  {"Hanggang may kahel", "na langit...",            215},
  {"...Lyrics finished.", "",                      220}
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

    // Countdown
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

    unsigned long zeroTime = millis();

    for (int i = 0; i < lyricCount; i++) {
      unsigned long targetTime = lyrics[i].startSec * 1000UL;

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
