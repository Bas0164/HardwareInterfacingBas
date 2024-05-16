const int potPin = A0; // Aansluiting van de pot meter
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; // Alle lampjes.

void setup() {
  // Hier staat dat de lampjes aan of uit kunnen.
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin); // Kijk hoe ver de potmeter is gedraaid.
  
  int numLeds = map(potValue, 0, 1023, 0, 7); // Bereken hoeveel lampjes we moeten aanzetten.
  
  // Loop om de lampjes aan- of uitzetten, afhankelijk van het aantal.
  for (int i = 0; i < 7; i++) {
    if (i < numLeds) {
      digitalWrite(ledPins[i], HIGH); // Led aan
    } else {
      digitalWrite(ledPins[i], LOW); // Led uit 
    }
  }
  
  delay(100); // Voeg een kleine vetraging toe
}