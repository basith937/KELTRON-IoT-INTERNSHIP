const int buttonPin = 2;
const int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(750);
  
  

}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Serial.println("1 2 3 4 5 6 7 8 9 10");
  } 
  delay(500);
  // put your main code here, to run repeatedly:

}
