#ifndef BUTTONS_H
#define BUTTONS_H
#include <Arduino.h>

#define BTN_FLAP 10
#define BTN_BACK 7
#define BTN_UP   4
#define BTN_DOWN 1
#define BTN_MENU 20

void buttonsInit();
bool btnFlap();
bool btnBack();
bool btnUp();
bool btnDown();
bool btnMenu();

#endif