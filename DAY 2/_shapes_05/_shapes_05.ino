#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);

   display.clearDisplay();
  
   display.setTextSize(2);
   display.setTextColor(SSD1306_WHITE);
   display.setCursor(10,20);

   display.println("Heelo,");
   display.setCursor(10, 40);     
   display.println("World");

   display.drawLine(10, 58, 118, 58, SSD1306_WHITE);

   display.drawRect(4, 12, 120, 50, SSD1306_WHITE);

   display.drawCircle(106, 24, 6, SSD1306_WHITE);

   display.drawTriangle(106, 38, 98, 52, 114, 52, SSD1306_WHITE);

   

   display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
