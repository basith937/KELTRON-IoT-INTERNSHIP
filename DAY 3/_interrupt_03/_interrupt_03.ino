int i;
int currentState = i++;
const int buttonPin = 2;
const int ledPin = 8;

volatile byte ledState = 0;

void setup() {
  // put your setup code here, to run once;
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, ledState);
  switch (currentState) {
    case 0:
    digitalWrite(ledPin, 0);
    break;

    case 1:
    digitalWrite(ledPin, 1);
    break;

    case 2:
    digitalWrite(ledPin, 1);
    delay(100);
    digitalWrite(ledPin, 0);
    delay(100);
    break;
  }
}
void toggleLED() {
  ledState = !ledState;
  delay(1000);
}

