int leds[] = {3, 4, 5};
int POTPin = A0;

void setup(){
  for (int i = 0; i < sizeof(leds)/sizeof(leds[i]); i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(POTPin, INPUT);
}

void loop() {
  int potValue = analogRead(POTPin);
  int level = map(potValue, 0, 1023, 1, 4);
  for (int i = 0; i < sizeof(leds)/sizeof(leds[i]); i++) {
    digitalWrite(leds[i], !digitalRead(leds[i]));
    delay(level * 200);
  }
}