const int ledPin = 8;
int command = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  switch (command) {
    case 1:
     digitalWrite(ledPin, HIGH);
     break;
    case 2:
     digitalWrite(ledPin, LOW);
     break;
    case 3:
     digitalWrite(ledPin, HIGH);
     delay(500);
     digitalWrite(ledPin, LOW);
     break;
    case 4:
     digitalWrite(ledPin, HIGH);
     delay(500);
     digitalWrite(ledPin, LOW);
     delay(500);
     digitalWrite(ledPin, HIGH);
     delay(500);
     digitalWrite(ledPin, LOW);
     break;
    default:
     digitalWrite(ledPin, LOW);
     break;  
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
