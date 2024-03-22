const int numLEDS = 12;
const int potPin = A0;
const int ledPins[numLEDS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  for (int i=0; i<numLEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int sensor1 = analogRead(potPin);
  int numLitLEDs = map(sensor1, 0, 1023, 0, numLEDS);
  for (int i=0; i<numLEDS; i++) {
    if (i < numLitLEDs) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  
  delay(100);
}