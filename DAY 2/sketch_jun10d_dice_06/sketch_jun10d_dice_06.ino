const int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
randomSeed(analogRead(0));
int diceRoll = random(1, 7);
 
for (int i = 0; i < diceRoll; i++){
  digitalWrite(ledPin, 1);
  delay(300);
  digitalWrite(ledPin, 0);
  delay(300);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
