void setup() {
  //Pin 11 die we een OUTPUT geven
  pinMode(11, OUTPUT);

  //Pin 12 die we een OUTPUT geven
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH); // Pin 11 op HIGH zetten (aan) (1, TRUE kan ook)
  delay(1000); // Voeg een 1 seconde pauze toe tussen de code
  digitalWrite(11, LOW); // Pin 11 op LOW zetten (uit) (0, FALSE kan ook)
  delay(1000); // Voeg een 1 seconde pauze toe tussen de code
  digitalWrite(12, HIGH); // Pin 12 op HIGH zetten (aan) (1, TRUE kan ook)
  delay(1000); // Voeg een 1 seconde pauze toe tussen de code
  digitalWrite(12, LOW); // Pin 12 op LOW zetten (uit) (0, FALSE kan ook)
  delay(1000); // Voeg een 1 seconde pauze toe tussen de code
}
