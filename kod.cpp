
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Wlasne znaki LCD

byte blockChar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte dumbbell[8] = {
  B10001,
  B10101,
  B11111,
  B11111,
  B11111,
  B11111,
  B10101,
  B10001
};

byte arrowChar[8] = {
  B00100,
  B00110,
  B11111,
  B11111,
  B11111,
  B00110,
  B00100,
  B00000
};

byte diamond[8] = {
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};


// Funkcja wyswietlania tekstu
void showScreen(const char* top, const char* bottom) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(top);
  lcd.setCursor(0, 1);
  lcd.print(bottom);
}


// Plynne przejscie przez wypelnienie ekranu
void transition(const char* top, const char* bottom) {

  // Wypelnianie ekranu
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.write(byte(0));

    lcd.setCursor(i, 1);
    lcd.write(byte(0));

    delay(35);
  }

  // Odkrywanie nowego napisu
  for (int i = 0; i < 16; i++) {

    lcd.setCursor(i, 0);
    lcd.print(top[i]);

    lcd.setCursor(i, 1);
    lcd.print(bottom[i]);

    delay(35);
  }
}


// Przesuwanie dlugiego napisu
void marquee(const char* message, int speed) {

  int len = strlen(message);

  char window[17];

  for (int i = 0; i < len + 16; i++) {

    for (int j = 0; j < 16; j++) {

      int position = i + j - 16;

      if (position >= 0 && position < len) {
        window[j] = message[position];
      } else {
        window[j] = ' ';
      }
    }

    window[16] = '\0';

    lcd.setCursor(0, 0);
    lcd.print(window);

    lcd.setCursor(0, 1);
    lcd.print("  GYM BOREK  ");

    delay(speed);
  }
}


// Animowana sztanga
void barAnimation() {

  for (int i = 0; i < 13; i++) {

    lcd.setCursor(0, 0);
    lcd.print("XTREME POWER");

    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(i, 1);
    lcd.write(byte(1));

    if (i > 0) {
      lcd.setCursor(i - 1, 1);
      lcd.print("-");
    }

    delay(110);
  }
}


void setup() {

  lcd.begin(16, 2);

  lcd.createChar(0, blockChar);
  lcd.createChar(1, dumbbell);
  lcd.createChar(2, arrowChar);
  lcd.createChar(3, diamond);

  lcd.setBacklight(1);

  showScreen(
    "   WELCOME TO   ",
    " XTREME FITNESS "
  );

  delay(1200);

  transition(
    "XTREME FITNESS ",
    "   GYM BOREK   "
  );

  delay(1000);
}


void loop() {

  // EKRAN 1 - LOGO
  transition(
    "XTREME FITNESS ",
    "   GYM BOREK   "
  );

  delay(1300);


  // EKRAN 2 - ANIMOWANA SZTANGA
  transition(
    "  NO LIMITS!   ",
    "  TRAIN HARD   "
  );

  barAnimation();

  delay(500);


  // EKRAN 3 - PRZEWIJANY BRANDING
  transition(
    "  WELCOME TO   ",
    "  XTREME GYM   "
  );

  marquee(
    "!!! XTREME FITNESS GYM BOREK !!!",
    115
  );


  // EKRAN 4 - MOTYWACYJNY
  transition(
    "  PUSH YOUR    ",
    "    LIMITS!    "
  );

  delay(1500);


  // EKRAN 5 - POWER
  transition(
    "  XTREME POWER ",
    "  NEVER STOP   "
  );

  for (int i = 0; i < 12; i++) {

    lcd.setCursor(15, 0);
    lcd.write(byte(3));

    delay(130);

    lcd.setCursor(15, 0);
    lcd.print(" ");

    lcd.setCursor(15, 1);
    lcd.write(byte(2));

    delay(130);

    lcd.setCursor(15, 1);
    lcd.print(" ");
  }


  // POWROT DO LOGO
  transition(
    "XTREME FITNESS ",
    "   GYM BOREK   "
  );

  delay(1500);
}
