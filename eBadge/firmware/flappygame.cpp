#include "flappygame.h"
#include "display.h"
#include "buttons.h"

float f_by = 32, f_bv = 0;
int f_px = 128, f_py = 32, f_sc = 0;
bool f_over = false;

void flappyReset() {
  f_by = 32; f_bv = 0; f_px = 128; f_sc = 0; f_over = false;
}

void flappyUpdate() {
  if (btnFlap() || btnUp()) f_bv = -2.5;
  f_by += f_bv; f_bv += 0.35;
  f_px -= 3;
  if (f_px < -10) { f_px = 128; f_py = random(20, 44); f_sc++; }

  if (f_by < 0 || f_by > 58 ||
      (f_px >= 10 && f_px <= 22 && (f_by < f_py - 14 || f_by > f_py + 14))) {
    f_over = true;
  }
}

void flappyDraw() {
  display.setTextColor(SH110X_WHITE);
  display.fillRect(16, (int)f_by, 6, 6, SH110X_WHITE);
  display.fillRect(f_px, 0, 10, f_py - 14, SH110X_WHITE);
  display.fillRect(f_px, f_py + 14, 10, 64 - (f_py + 14), SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Score: "); display.print(f_sc);
}

bool flappyIsOver() { return f_over; }