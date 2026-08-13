#include "menu.h"
#include "display.h"
#include "buttons.h"
#include <Arduino.h>

int menuSel = 0;
const int NUM_ITEMS = 3;
const char* items[] = {"Show Badge", "Play Flappy", "Play Dino"};

void drawMenuScreen() {
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("--- MAIN MENU ---");
  
  for (int i = 0; i < NUM_ITEMS; i++) {
    display.setCursor(10, 25 + (i * 12));
    if (i == menuSel) {
      display.print("> ");
    } else {
      display.print("  ");
    }
    display.println(items[i]);
  }
}

void menuHandleInput() {
  if (btnDown()) { 
    menuSel = (menuSel + 1) % NUM_ITEMS; 
    delay(150);
  }
  if (btnUp()) { 
    menuSel = (menuSel - 1 + NUM_ITEMS) % NUM_ITEMS; 
    delay(150);
  }
}