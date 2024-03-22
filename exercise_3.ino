int buttonState = 0;
int buttonPin = 2;

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

int leds[] = 
{
  led1,led2,led3,led4,led5,led6
};

void setup() {
  setLedPinMode();
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(0));
}

void loop() {
  buttonState = digitalRead(buttonPin);
  boolean buttonPressed = buttonState == HIGH;
  int randomNumber = random(1,7);

  if(buttonPressed){
    resetLeds();
    delay(500);
    rollAnimation();
    delay(500);
    rollDice(randomNumber);
  }
    delay(100);
}

void rollAnimation(){
  for(int i = 0; i<6 ; i++){
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
  for(int i = 5; i >= 0 ; i--){
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
}

void resetLeds(){
  for(int i = 0; i<6 ; i++){
    digitalWrite(leds[i], LOW);
  }
}

int rollDice (int randomNumber){
  for(int i = 0; i<randomNumber ; i++){
    digitalWrite(leds[i], HIGH);
  }
}

void setLedPinMode()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}