#include "display.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool displayInit()
{
  Wire.begin(5, 6);
  Wire.setClock(400000);

  if (!display.begin(SCREEN_ADDRESS, true))
  {
    Serial.println("OLED init failed — continuing without display.");
    return false;
  }
  display.clearDisplay();
  display.display();
  return true;
}