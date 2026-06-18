const int ledPin = 9;
int brightness = 255;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
analogWrite(ledPin, brightness);
if (brightness > 170) {
  delay(1000);
} else if (brightness > 85) {
  delay(500);
} else{
  delay(200);
}

brightness = brightness - 50;

if (brightness < 0){
  brightness = 255;
  delay(5000);
}
else{
  digitalWrite(13, 1);
  delay(4000);
  digitalWrite(13, 0);
}
}
