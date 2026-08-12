#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <Preferences.h>

void storageInit();                          // call once in setup()
String loadName();
String loadDept();
void saveName(String name);
void saveDept(String dept);

#endif