// Definieer de pinnen
const int ledPin1 = 8;
const int ledPin2 = 10;
const int buttonPin = 12;

// Variabelen om de status bij te houden
int buttonState = 0;
int lastButtonState = 0;
int counter = 0;

void setup() {
  // Stel de LED-pinnen in als output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Stel de knop pin in als input met interne pull-up weerstand
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Lees de huidige staat van de knop
  buttonState = digitalRead(buttonPin);

  // Controleer of de knop is ingedrukt
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Verhoog de teller
    counter++;

    // Update de LED's
    if (counter % 2 == 0) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
    } else {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }

    // Wacht 50ms om debounce te voorkomen
    delay(50);
  }

  // Update de laatste knopstatus
  lastButtonState = buttonState;
}
