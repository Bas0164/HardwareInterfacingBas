// Pindefinitie
const int ledPin1 = 10;
const int ledPin2 = 13;

void setup() {
  // LED-pinnen instellen als output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // LED 1 aan, LED 2 uit
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(1500); // 1,5 seconden wachten

  // LED 1 uit, LED 2 aan
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1500); // 1,5 seconden wachten
}
