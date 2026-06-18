const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  // put your setup code here, to run onc
}

void loop() {
  blinkLED(5 , 250);
}

void blinkLED(int times, int aswin) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, 1);
    delay(aswin);
    digitalWrite(ledPin, 0);
    delay(aswin);

  }
  delay(2000);
}

  // put your main code here, to run repeatedly}
