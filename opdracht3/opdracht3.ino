const int buttonPin = 5; // Pin waarop de knop is aangesloten
const int ledPin = 11; // Pin waarop de LED is aangesloten
bool isLightOn = false; // Variabele om de status van het lampje bij te houden

void setup() {
  pinMode(ledPin, OUTPUT); // Zet de LED pin als uitgang
  pinMode(buttonPin, INPUT); // Zet de knop pin als ingang
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Als de knop wordt ingedrukt:
    isLightOn = !isLightOn; // Wissel de status van het lampje
    while (digitalRead(buttonPin) == HIGH) {} // Wacht tot de knop wordt losgelaten om meerdere activeringen te voorkomen
    delay(50); // Voeg een kleine vertraging toe
  }

  if (isLightOn) { // Als het lampje aan moet zijn:
    digitalWrite(ledPin, HIGH); // Zet de LED aan
  } else { // Anders..
    digitalWrite(ledPin, LOW); // Zet de LED uit
  }
}
