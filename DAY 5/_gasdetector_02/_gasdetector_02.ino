#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

const int gasSensorPin = A0;
const int buzzerPin = 8;

int gasValue = 0;

// Adjust this threshold according to your sensor readings
const int gasThreshold = 400;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10, 20);
  display.println("Gas Detector");
  display.display();
  delay(2000);
}

void loop() {
  gasValue = analogRead(gasSensorPin);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Gas Monitoring");

  display.setCursor(0, 20);
  display.print("Gas Value: ");
  display.println(gasValue);

  if (gasValue > gasThreshold) {
    display.setCursor(0, 45);
    display.setTextSize(2);
    display.println("ALERT!");

    tone(buzzerPin, 1000); // 1 kHz buzzer
  } else {
    display.setCursor(0, 45);
    display.setTextSize(1);
    display.println("Air Normal");

    noTone(buzzerPin);
  }

  display.display();
  delay(500);
}
