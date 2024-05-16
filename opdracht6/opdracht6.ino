#include <Servo.h>

Servo myServo; // Maak een Servo object aan
int yAxisPin = A0; // Joystick Y-as pin
int xAxisPin = A1; // Joystick X-as pin
int buttonPin = 2; // Joystick knop pin
int xAxisValue; // Variabele voor de X-as waarde van de joystick
int yAxisValue; // Variabele voor de Y-as waarde van de joystick
int servoControlPin = 11; // Servo motor pin
int servoPosition = 0; // Initiële positie van de servo

void setup() {
  Serial.begin(9600); // Start seriële communicatie op 9600 baud
  myServo.attach(servoControlPin); // Koppel de servo aan de opgegeven pin
  myServo.write(servoPosition); // Zet servo op de beginpositie
  pinMode(xAxisPin, INPUT); // Stel de X-as pin in als input
  pinMode(yAxisPin, INPUT); // Stel de Y-as pin in als input
  pinMode(buttonPin, INPUT_PULLUP); // Stel de knop pin in als input met interne pull-up weerstand
}

void loop() {
  controlServo(); // Roep de functie aan om de servo te besturen

  // Controleer of de knop is ingedrukt
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed(); // Roep de functie aan bij knop indrukken
  }
}

void controlServo() {
  xAxisValue = analogRead(xAxisPin); // Lees de waarde van de X-as van de joystick
  yAxisValue = analogRead(yAxisPin); // Lees de waarde van de Y-as van de joystick

  if (xAxisValue < 300) { // Controleer of de joystick naar links wordt bewogen
    if (servoPosition > 0) { // Controleer of de servo niet onder de minimale hoek gaat
      servoPosition -= 1; // Verlaag de servo hoek met 1 graad
      myServo.write(servoPosition); // Beweeg de servo naar de nieuwe hoek
      delay(10); // Korte vertraging voor stabiliteit
    }
  } else if (xAxisValue > 700) { // Controleer of de joystick naar rechts wordt bewogen
    if (servoPosition < 120) { // Controleer of de servo niet boven de maximale hoek gaat
      servoPosition += 1; // Verhoog de servo hoek met 1 graad
      myServo.write(servoPosition); // Beweeg de servo naar de nieuwe hoek
      delay(10); // Korte vertraging voor stabiliteit
    }
  }
}

void buttonPressed() {
  // Draai de servo van 0 naar 120 graden en weer terug
  for (int angle = 0; angle <= 120; angle += 2) {
    myServo.write(angle); // Stuur de servo naar de huidige hoek
    delay(15); // Voeg een kleine vertraging toe voor stabiliteit
  }
  delay(500); // Wacht 0.5 seconden voordat de servo terugkeert naar de beginpositie
  myServo.write(0); // Beweeg de servo terug naar 0 graden
  delay(15); // Voeg een korte vertraging toe voor stabiliteit
}
