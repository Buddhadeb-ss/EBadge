#include "display.h"
#include "buttons.h"
#include "storage.h"
#include "webportal.h"
#include "badge.h"
#include "menu.h"
#include "flappygame.h"
#include "dinogame.h"

enum State { ST_CONFIG, ST_BADGE, ST_MENU, ST_FLAPPY, ST_DINO, ST_FLAPPY_OVER, ST_DINO_OVER };
State state = ST_CONFIG;

uint32_t nextFrame = 0;
bool displayOk = false;

void drawGameOver(int score) {
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(25, 17);
  display.println("GAME OVER");
  display.setCursor(25, 37);
  display.print("Score: "); display.print(score);
  display.setCursor(15, 54);
  display.println("Press MENU to Exit");
}

void drawConfigScreen() {
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 12);
  display.println("Configuring...");
  display.setCursor(10, 30);
  display.println("Connect to WiFi:");
  display.setCursor(10, 44);
  display.println("eBadge-Setup");
}

void render() {
  if (!displayOk) return;

  display.clearDisplay();
  switch (state) {
    case ST_CONFIG:      drawConfigScreen(); break;
    case ST_BADGE:        drawBadgeScreen();