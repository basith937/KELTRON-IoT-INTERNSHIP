#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int hours = 0;
int minutes = 0;
int seconds = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);

   display.begin(SSD1306_SWITCHCAPVCC,0x3C);

   display.clearDisplay();
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  if (Serial.available() > 0) {
    hours = Serial.parseInt();
    minutes = Serial.parseInt();
    seconds = Serial.parseInt();

    while (Serial.available()) {
      Serial.read();
    }
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    seconds++;

    if (seconds >= 60) {
      seconds = 0;
      minutes++;

      if (minutes >= 60) {
        minutes = 0;
        hours++;

        if (hours >= 24) {
          hours = 0;
        }
      }
    }
  }

  displayTime();
}

void displayTime() {

  display.clearDisplay();
  drawScreen_1();
  display.setCursor(16, 24);

  display.print(hours);
  display.print(":");
  display.print(minutes);
  display.print(":");
  display.print(seconds);

  display.display();
}

// [BEGIN lopaka generated]
static const unsigned char PROGMEM image_Ble_connected_bits[] = {0x07,0xc0,0x1f,0xf0,0x3e,0xf8,0x7e,0x7c,0x76,0xbc,0xfa,0xde,0xfc,0xbe,0xfe,0x7e,0xfc,0xbe,0xfa,0xde,0x76,0xbc,0x7e,0x7c,0x3e,0xf8,0x1f,0xf0,0x07,0xc0};

static const unsigned char PROGMEM image_off_text_bits[] = {0x67,0x70,0x94,0x40,0x96,0x60,0x94,0x40,0x64,0x40};

void drawScreen_1(void) {
    display.clearDisplay();
    // rect 1
    display.drawRect(1, 0, 126, 64, 1);
    // Ble_connected
    display.drawBitmap(99, 15, image_Ble_connected_bits, 15, 15, 1);
    // circle 3
    display.drawCircle(106, 22, 11, 1);
    // off_text
    display.drawBitmap(100, 43, image_off_text_bits, 12, 5, 1);
    // rect 5
    display.drawRect(96, 39, 21, 13, 1);
    display.display();
}
// [END lopaka generated]
