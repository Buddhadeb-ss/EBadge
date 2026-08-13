
#include "buttons.h"

const uint8_t PINS[] = {BTN_FLAP, BTN_BACK, BTN_UP, BTN_DOWN, BTN_MENU};

void buttonsInit()
{
  for (uint8_t p : PINS) pinMode(p, INPUT_PULLUP);
}

bool btnFlap()
{
  return !digitalRead(BTN_FLAP);
}
bool btnBack()
{
  return !digitalRead(BTN_BACK);
}
bool btnUp()
{
  return !digitalRead(BTN_UP);
}
bool btnDown()
{
  return !digitalRead(BTN_DOWN);
}
bool btnMenu()
{
  return !digitalRead(BTN_MENU);
}