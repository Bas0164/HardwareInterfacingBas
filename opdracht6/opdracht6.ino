#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Installeer de LCD op I2C-adres 0x27 en gebruik 16 kolommen en 2 rijen
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pindefinities voor knoppen
const int buttonPin1 = 2; // Pin voor knop 1
const int buttonPin2 = 3; // Pin voor knop 2

// Variabelen voor tijdsregistratie
unsigned long startTime;
bool running = false;
bool buttonPressed1 = false;
bool buttonPressed2 = false;
unsigned long buttonPressStartTime1 = 0;
unsigned long buttonPressStartTime2 = 0;
bool resetRequested = false;
unsigned long lastReleaseTime = 0;
const unsigned long debounceDelay = 50; // debounce delay in milliseconds

// Hartjes symbool
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  // Initialiseer de LCD
  lcd.init();
  lcd.backlight();

  // Maak het hartje karakter
  lcd.createChar(0, heart);

  // Initialiseer de knoppen als ingangen
  pinMode(buttonPin1, INPUT_PULLUP); // Gebruik interne pull-up weerstand
  pinMode(buttonPin2, INPUT_PULLUP); // Gebruik interne pull-up weerstand

  // Welkomstbericht op de LCD
  lcd.setCursor(0, 0);
  lcd.print("Bergen op Zoom ");
  lcd.write(byte(0)); // Schrijf het hartje
}

void loop() {
  // Controleer knop 1
  if (digitalRead(buttonPin1) == LOW) { // Knoppen zijn actief laag
    if (!buttonPressed1 && (millis() - buttonPressStartTime1 >= debounceDelay)) {
      buttonPressed1 = true;
      buttonPressStartTime1 = millis();
    }
  } else {
    if (buttonPressed1) {
      if (!running) {
        running = true;
        startTime = millis(); // Start de timer
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(getFormattedTime());
        lcd.setCursor(0, 1);
        lcd.print("Lap: ");
      } else {
        if (millis() - buttonPressStartTime1 >= 2000) { // Als knop 2 seconden lang is ingedrukt
          lcd.setCursor(0, 1);
          lcd.print("Lap: ");
          lcd.print(getFormattedTime());
          delay(500); // Voeg een kleine vertraging toe om meerdere laps te voorkomen
        }
      }
      buttonPressed1 = false;
    }
  }

  // Controleer knop 2
  if (digitalRead(buttonPin2) == LOW) { // Knoppen zijn actief laag
    if (!buttonPressed2 && (millis() - buttonPressStartTime2 >= debounceDelay)) {
      buttonPressed2 = true;
      buttonPressStartTime2 = millis();
    }
  } else {
    if (buttonPressed2) {
      // Toggle de timer status tussen pauze en hervatten
      running = !running;
      buttonPressed2 = false;
    }
  }

  // Controleer als beide knoppen zijn losgelaten
  if (!buttonPressed1 && !buttonPressed2) {
    if (millis() - lastReleaseTime >= debounceDelay) {
      resetRequested = true;
    }
  } else {
    lastReleaseTime = millis();
  }

  // Als reset is aangevraagd, reset de timer en lap
  if (resetRequested) {
    resetTimerAndLap();
    resetRequested = false;
  }

  // Controleer of de stopwatch aan het lopen is
  if (running) {
    // Toon de tijd op de LCD
    lcd.setCursor(0, 0);
    lcd.print(getFormattedTime());
  }
}

// Functie om de geformatteerde tijd op te halen (hh:mm:ss)
String getFormattedTime() {
  unsigned long currentTime = millis() - startTime;
  int seconds = (currentTime / 1000) % 60;
  int minutes = (currentTime / (1000 * 60)) % 60;
  int hours = (currentTime / (1000 * 60 * 60)) % 24;

  // Formatteer de tijd als een string (hh:mm:ss)
  String formattedTime = "";
  if (hours < 10) formattedTime += "0";
  formattedTime += String(hours) + ":";
  if (minutes < 10) formattedTime += "0";
  formattedTime += String(minutes) + ":";
  if (seconds < 10) formattedTime += "0";
  formattedTime += String(seconds);

  return formattedTime;
}

// Functie om de timer en lap te resetten
void resetTimerAndLap() {
  startTime = 0;
  running = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bergen op Zoom ");
  lcd.write(byte(0)); // Schrijf het hartje
}
