#include "menu.h"
#include "display.h"
#include "buttons.h"

int menuSel = 0;

void drawMenuScreen() {
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);

  display.setCursor(10, 5);
  display.println("SELECT GAME");

  display.setCursor(10, 25);
  display.println(menuSel == 0 ? "> Flappy Bird" : "  Flappy Bird");

  display.setCursor(10, 40);
  display.println(menuSel == 1 ? "> Dino Jump" : "  Dino Jump");
}

void menuHandleInput() {
  if (btnUp())   { menuSel = 0; delay(150); }
  if (btnDown()) { menuSel = 1; delay(150); }
}