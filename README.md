Projekt: Xtreme Fitness - Wyświetlacz LCD
Ten projekt to animowany program na wyświetlacz LCD (16x2) sterowany przez Arduino, stworzony dla "Xtreme Fitness Gym Borek". Wykorzystuje niestandardowe znaki (custom characters) oraz różne efekty wizualne, takie jak płynne przejścia, przewijanie tekstu i animacje.

Wymagania
Płytka kompatybilna z Arduino (np. Arduino Uno, Nano).

Wyświetlacz LCD 16x2.

Moduł I2C do wyświetlacza (opcjonalnie, ale sugerowane ze względu na bibliotekę w kodzie - Adafruit_LiquidCrystal).

Biblioteka Adafruit LiquidCrystal (do zainstalowania z poziomu menedżera bibliotek Arduino IDE).

Funkcjonalność
Program działa w pętli, wyświetlając serię ekranów promocyjnych i motywacyjnych z różnymi efektami:

Ekran powitalny: Wstępny ekran wyświetlany podczas uruchamiania (setup).

Logo: Klasyczne wyświetlenie nazwy siłowni z efektem przejścia.

Animacja sztangi: Ekran "NO LIMITS! TRAIN HARD" z animacją przesuwającej się sztangi na dolnej linii.

Przewijany branding (Marquee): Przesuwający się tekst "!!! XTREME FITNESS GYM BOREK !!!" na górnej linii.

Ekran motywacyjny: Statyczny tekst "PUSH YOUR LIMITS!".

Ekran Power: Tekst z migającymi, niestandardowymi znakami (strzałka i diament) po prawej stronie.

Niestandardowe znaki (Custom Characters)
Kod definiuje 4 własne grafiki (matryce 5x8 pikseli), które nadają wyświetlaczowi unikalny wygląd:

Pełny blok (blockChar): Używany do tworzenia efektu płynnego przejścia (wymazywania/wypełniania ekranu). byte(0)

Hantla/Sztanga (dumbbell): Wykorzystywana w animacji "barAnimation". byte(1)

Strzałka (arrowChar): Migający element dekoracyjny. byte(2)

Diament (diamond): Migający element dekoracyjny. byte(3)

Opis najważniejszych funkcji
showScreen(const char* top, const char* bottom): Błyskawicznie czyści ekran i wypisuje dwa wiersze tekstu.

transition(const char* top, const char* bottom): Tworzy efekt przejścia typu "wipe". Najpierw wypełnia ekran pełnymi blokami, a następnie znak po znaku odkrywa nowy tekst, nadpisując bloki.

marquee(const char* message, int speed): Funkcja odpowiadająca za efekt płynnego przesuwania długiego tekstu od prawej do lewej krawędzi ekranu.

barAnimation(): Renderuje krótką animację sztangi (hantli) "jadącej" z lewej do prawej strony ekranu, zostawiającej za sobą "gryf" ze znaków pauzy (-).

Uruchomienie
Podłącz wyświetlacz LCD do Arduino (zazwyczaj piny A4 (SDA) i A5 (SCL) dla modułu I2C).

Zainstaluj wymaganą bibliotekę Adafruit LiquidCrystal.

Jeśli Twój moduł I2C ma inny adres (np. 0x27 lub 0x3F), może być konieczna zmiana inicjalizacji:
Zamiast Adafruit_LiquidCrystal lcd(0);
Spróbuj: Adafruit_LiquidCrystal lcd(0x27); (jeśli używasz innej wersji biblioteki LiquidCrystal_I2C, inicjalizacja będzie wyglądać inaczej).

Skonfiguruj środowisko Arduino IDE dla swojej płytki, skompiluj i wgraj kod.
