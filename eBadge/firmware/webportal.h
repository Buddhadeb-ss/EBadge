#ifndef WEBPORTAL_H
#define WEBPORTAL_H
#include <Arduino.h>

void webInit();
void webHandle();
void webShutdown();
bool isConfigActive();
#endif