#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

long duration;
float distanceCm;
float distanceIn;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH, 30000);

  // Handle no echo received
  if (duration == 0) {
    distanceCm = 999;
  } else {
    distanceCm = duration * 0.0343 / 2;
  }

  distanceIn = distanceCm / 2.54;

  // Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm, 1);
  Serial.print(" cm | ");
  Serial.print(distanceIn, 1);
  Serial.println(" in");

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Parking Sensor");

  display.setTextSize(2);
  display.setCursor(0, 18);
  display.print(distanceCm, 1);
  display.println(" cm");

  display.setCursor(0, 42);
  display.print(distanceIn, 1);
  display.println(" in");

  display.display();

  // ===== Parking Sensor Buzzer =====

  if (distanceCm <= 10) {
    // Very close: continuous tone
    tone(buzzerPin, 2500);

  } else if (distanceCm <= 100) {
    // Beep rate changes with distance
    int beepDelay = map((int)distanceCm, 10, 100, 50, 1000);

    tone(buzzerPin, 2500);
    delay(50);

    noTone(buzzerPin);
    delay(beepDelay);

  } else {
    // Out of range: silent
    noTone(buzzerPin);
    delay(100);
  }
}
