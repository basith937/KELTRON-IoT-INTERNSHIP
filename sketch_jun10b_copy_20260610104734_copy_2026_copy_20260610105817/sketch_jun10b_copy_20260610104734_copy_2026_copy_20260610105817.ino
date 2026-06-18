const int ledPin = 8;
int blink = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(blink < 10){
    do {
    digitalWrite(ledPin, 1);
    delay(250);
    digitalWrite(ledPin, 0);
    delay(250);
    blink++;
  } while (blink < 10);
 }
   
}
