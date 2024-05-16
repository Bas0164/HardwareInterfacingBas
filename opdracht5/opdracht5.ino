#include <Servo.h>

Servo myServo; // Maak een Servo object aan

int buttonPin1 = 6; // Pin waarop de eerste drukknop is aangesloten
int buttonPin2 = 5; // Pin waarop de tweede drukknop is aangesloten

void setup() {
  myServo.attach(11); // Sluit de servomotor aan op pin 11
  myServo.write(0);   // Zet de servomotor in de beginpositie van 0 graden
  
  pinMode(buttonPin1, INPUT); // Zet de pin van de eerste drukknop als input
  pinMode(buttonPin2, INPUT); // Zet de pin van de tweede drukknop als input
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1); // Lees de staat van de eerste drukknop
  int buttonState2 = digitalRead(buttonPin2); // Lees de staat van de tweede drukknop
  
  if (buttonState1 == HIGH && buttonState2 == HIGH) {
    moveServo(120, 1000); // Draai de servomotor naar 120° in 1s
    delay(2000); // Voeg een 2 seconde pauze toe tussen de code
    moveServo(0, 1000); // Draai de servomotor terug naar 0° in 1s
  } else if (buttonState1 == HIGH) {
    moveServo(120, 1000); // Draai de servomotor naar 120° in 1s
    moveServo(0, 1000); // Draai de servomotor terug naar 0° in 1s
  } else if (buttonState2 == HIGH) {
    moveServo(120, 500); // Draai de servomotor naar 120° in 0,5s
    moveServo(0, 1000); // Draai de servomotor terug naar 0° in 1s
  }
}

void moveServo(int angle, int duration) {
  int initialAngle = myServo.read(); // Huidige positie van de servomotor
  int finalAngle = angle; // Gewenste positie van de servomotor
  
  // Bepaal de stapgrootte op basis van de gewenste duur
  float step = (finalAngle - initialAngle) / (float)duration;
  
  // Beweeg de servomotor naar de gewenste positie
  for (int i = 0; i <= duration; i++) {
    myServo.write(initialAngle + step * i);
    delay(1); // Voeg een kleine vertraging toe
  }
}
