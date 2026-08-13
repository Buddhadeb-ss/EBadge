#include <Arduino.h>
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
  
  // Coordinates adjusted to ensure they fit entirely on the 48-pixel high screen
  display.setCursor(35, 5);
  display.println("GAME OVER");
  
  display.setCursor(40, 18);
  display.print("Score: "); display.print(score);
  
  // Split across two lines to fit the 128-pixel width
  display.setCursor(25, 30);
  display.println("Press MENU to");
  display.setCursor(35, 40);
  display.println("play again");
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
    case ST_BADGE:       drawBadgeScreen(); break;
    case ST_MENU:        drawMenuScreen(); break;
    case ST_FLAPPY:      flappyDraw(); break;
    case ST_DINO:        dinoDraw(); break;
    case ST_FLAPPY_OVER: drawGameOver(f_sc); break;
    case ST_DINO_OVER:   drawGameOver(d_sc); break;
  }
  
  display.display();
}

void setup() {
  Serial.begin(115200);

  buttonsInit();
  storageInit();
  displayOk = displayInit();

  webInit();
  state = ST_CONFIG;
}

void loop() {
  // 1. Config Phase
  if (state == ST_CONFIG) {
    webHandle();
    if (!isConfigActive()) {
      webShutdown();
      state = ST_BADGE;
    }
  } 
  else {
    // Global Menu Return - Restricted to running games or the badge screen
    if ((state == ST_BADGE || state == ST_FLAPPY || state == ST_DINO) && btnMenu()) {
      state = ST_MENU;
      delay(200);
    }
  }

  // 2. Menu & Game Over Input 
  if (state == ST_MENU) {
    menuHandleInput();
    
    // Now using MENU button to make selections in the menu
    if (btnMenu()) {
      if (menuSel == 0) state = ST_BADGE;
      if (menuSel == 1) { flappyReset(); state = ST_FLAPPY; }
      if (menuSel == 2) { dinoReset(); state = ST_DINO; }
      delay(200);
    }
  }
  else if (state == ST_FLAPPY_OVER || state == ST_DINO_OVER) {
    // Now using MENU button to go back to the menu and play again
    if (btnMenu()) {
      state = ST_MENU;
      delay(200);
    }
  }

  // 3. Game Physics & Render at ~30 FPS
  if (millis() >= nextFrame) {
    nextFrame = millis() + 33;

    if (state == ST_FLAPPY) {
      flappyUpdate();
      if (flappyIsOver()) state = ST_FLAPPY_OVER;
    }
    else if (state == ST_DINO) {
      dinoUpdate();
      if (dinoIsOver()) state = ST_DINO_OVER;
    }

    render();
  }
}