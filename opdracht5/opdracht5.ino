#include <Servo.h>

const int button1Pin = 2;  // Pin voor knop 1
const int button2Pin = 3;  // Pin voor knop 2
const int servoPin = 12;   // Pin voor de servo

Servo myServo;

void setup() {
  pinMode(button1Pin, INPUT_PULLUP); // pull-up weerstand voor knop 1
  pinMode(button2Pin, INPUT_PULLUP); // pull-up weerstand voor knop 2
  myServo.attach(servoPin);
  myServo.write(0); // Startpositie
}

void loop() {
  static unsigned long lastDebounceTime1 = 0;
  static unsigned long lastDebounceTime2 = 0;
  unsigned long debounceDelay = 50; // Debounce tijd in milliseconden

  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);

  if (millis() - lastDebounceTime1 > debounceDelay) {
    if (button1State == LOW && button2State!= LOW) { // Alleen knop 1 ingedrukt
      moveServo(5000, 0, 5000, true);
      lastDebounceTime1 = millis();
    }
  }

  if (millis() - lastDebounceTime2 > debounceDelay) {
    if (button2State == LOW && button1State!= LOW) { // Alleen knop 2 ingedrukt
      moveServo(500, 0, 500, false);
      lastDebounceTime2 = millis();
    } else if (button1State == LOW && button2State == LOW) { // Beide knoppen ingedrukt
      moveServo(5000, 2000, 500, true);
      lastDebounceTime1 = millis(); // Reset debounce timer voor knop 1
    }
  }
}

void moveServo(int forwardTime, int holdTime, int backwardTime, bool singleButton) {
  int startAngle = 0;
  int endAngle = 120;

  // Beweeg naar voren
  for (int pos = startAngle; pos <= endAngle; pos++) {
    myServo.write(pos);
    delay(forwardTime / (endAngle - startAngle));
  }

  // Houd positie vast
  if (!singleButton || (singleButton && holdTime > 0)) {
    delay(holdTime);
  }

  // Beweeg terug
  for (int pos = endAngle; pos >= startAngle; pos--) {
    myServo.write(pos);
    delay(backwardTime / (endAngle - startAngle));
  }
}
