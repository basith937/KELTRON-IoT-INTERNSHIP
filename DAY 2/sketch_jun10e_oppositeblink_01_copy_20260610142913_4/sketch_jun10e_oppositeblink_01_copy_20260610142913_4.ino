const int buttonPin = 2;
const int ledPin = 9;

int ledState = LOW;
int lastButtonState = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {

    ledState = !ledState;

    digitalWrite(ledPin, ledState);
    
    delay(50);
  }

  lastButtonState = buttonState;
}
