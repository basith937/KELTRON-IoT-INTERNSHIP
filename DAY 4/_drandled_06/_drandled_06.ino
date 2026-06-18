const int analogPin = A0;
const int digitalPin = 2;
const int ledPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(digitalPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("Analog LDR Reading Started!");
  Serial.println("---------------------------");

}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(analogPin);

  int digitalVal = digitalRead(digitalPin);

  Serial.print("Analog Value: ");
  Serial.print(analogVal);
  Serial.println("\t | \tDigital Value: ");
  Serial.println(digitalVal);

  if (digitalVal == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);

}