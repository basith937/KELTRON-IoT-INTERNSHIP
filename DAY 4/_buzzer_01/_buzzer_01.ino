const int buzzerPin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzerPin, 10000);
  delay(500);

  tone(buzzerPin, 600);
  delay(500);

}