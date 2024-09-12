// Definieer de pinnen
const int ledPins[] = {2, 3, 4, 5, 6, 7};
const int numLeds = 6;
const int potPin = A0;

// Variabele om de potmeterwaarde bij te houden
int potValue = 0;

void setup() {
  // Stel de LED-pinnen in als output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Lees de waarde van de potmeter
  potValue = analogRead(potPin);

  // Bereken het aantal LEDs dat uit moet zijn
  int numLedsOff = map(potValue, 0, 1023, 0, numLeds + 1);

  // Zet de LEDs aan of uit op basis van de potmeterwaarde
  for (int i = 0; i < numLeds; i++) {
    if (i < numLedsOff) {
      digitalWrite(ledPins[i], LOW); // LED uit
    } else {
      digitalWrite(ledPins[i], HIGH); // LED aan
    }
  }
}
