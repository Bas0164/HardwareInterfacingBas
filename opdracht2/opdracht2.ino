void setup() {
  // Zet alle pinnen als OUTPUT met behulp van een loop
  for (int pin = 0; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // Start de 2 functies  
  FlowRight(40);
  FlowLeft(40);
}

// Functie om de LEDs van rechts naar links te laten stromen
void FlowRight(int tijd){
  for (int pin = 7; pin >= 0; pin--) { // Loop van de hoogste naar de laagste pin
    digitalWrite(pin, HIGH); // Zet de huidige pin aan
    delay(tijd); // Voeg een 1 seconde pauze toe tussen de code
    digitalWrite(pin, LOW); // Zet de huidige pin uit
    delay(tijd); // Voeg een 1 seconde pauze toe tussen de code
  }
}

// Functie om de LEDs van links naar rechts te laten stromen
void FlowLeft(int tijd){
  for (int pin = 0; pin <= 7; pin++) { // Loop van de laagste naar de hoogste pin
    digitalWrite(pin, HIGH); // Zet de huidige pin aan
    delay(tijd); // Voeg een 1 seconde pauze toe tussen de code
    digitalWrite(pin, LOW); // Zet de huidige pin uit
    delay(tijd); // Voeg een 1 seconde pauze toe tussen de code
  }
}
