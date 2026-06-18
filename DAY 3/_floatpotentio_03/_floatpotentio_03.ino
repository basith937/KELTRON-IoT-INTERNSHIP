const int potPin = A0;
int potValue = 0;
float voltage = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);

  voltage = convertToVoltage(potValue);
  
  Serial.print("Raw Value: ");
  Serial.print(potValue);
  Serial.print("  |  Mapped Voltage: ");
  Serial.print("voltage");
  Serial.println(" V");

  delay(100);

}

float convertToVoltage(int rawValue) {
  float calculatedVoltage = rawValue * (5.0 / 1023.0);

  return calculatedVoltage;
}
