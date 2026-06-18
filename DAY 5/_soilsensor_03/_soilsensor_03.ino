#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

const int soilPin = A0;

// Calibrate these values for your sensor
const int dryValue = 1023;   // Sensor in air
const int wetValue = 300;    // Sensor in water

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("SOIL TEST");
  display.display();

  delay(2000);
}

void loop() {
  int sensorValue = analogRead(soilPin);

  int moisturePercent = map(sensorValue,
                            dryValue,
                            wetValue,
                            0,
                            100);

  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Raw: ");
  Serial.print(sensorValue);
  Serial.print("  Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Soil Moisture Monitor");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(moisturePercent);
  display.println("%");

  display.setTextSize(1);
  display.setCursor(0, 50);

  if (moisturePercent < 30) {
    display.println("Soil is DRY");
  }
  else if (moisturePercent < 70) {
    display.println("Moisture OK");
  }
  else {
    display.println("Soil is WET");
  }

  display.display();

  delay(1000);
}
