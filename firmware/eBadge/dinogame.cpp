
#include "dinogame.h"
#include "display.h"
#include "buttons.h"
#include <Arduino.h>

float d_y = 52, d_v = 0;
int d_ox = 128, d_sc = 0;
bool d_duck = false;
bool d_over = false;

void dinoReset()
{
  d_y = 52; d_v = 0; d_ox = 128; d_sc = 0; d_duck = false; d_over = false;
}

void dinoUpdate()
{
  d_duck = btnDown();
  if ((btnUp() || btnFlap()) && d_y >= 52 && !d_duck) { d_v = -6.5; }
  d_y += d_v; d_v += 0.45;
  if (d_y > 52) { d_y = 52; d_v = 0; }
  d_ox -= 4;
  if (d_ox < -10) { d_ox = 128; d_sc++; }

  int dinoH = d_duck ? 8 : 12;
  int dinoYCoord = d_duck ? 44 : (int)d_y - 12;
  if (d_ox >= 16 && d_ox <= 26 && (dinoYCoord + dinoH > 40)) {
    d_over = true;
  }
}

void dinoDraw() {
  display.setTextColor(SH110X_WHITE);
  display.drawFastHLine(0, 52, 128, SH110X_WHITE);

  if (d_duck) {
    display.fillRect(20, 44, 14, 8, SH110X_WHITE);
  } else {
    display.fillRect(20, (int)d_y - 12, 8, 12, SH110X_WHITE);
  }
  display.fillRect(d_ox, 40, 8, 12, SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Score: "); display.print(d_sc);
}

bool dinoIsOver() { return d_over; }