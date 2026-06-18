const int ledPin = 8;
int blink;
int i;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  i = 0;
  while(i < 10){
    blink = 0; 
  while(blink < i){
    digitalWrite(ledPin, 1);
    delay(250);
    digitalWrite(ledPin, 0);
    delay(250);
    blink++;
  }
  delay(1500);
  i++;
  }
   
}
