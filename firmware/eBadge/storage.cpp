#include "storage.h"

Preferences prefs; 

void storageInit() {
  prefs.begin("badge", false);
}

String loadName() {
  return prefs.getString("name", "Not Set");
}

String loadDept() {
  return prefs.getString("dept", "Not Set");
}

void saveName(String name) {
  prefs.putString("name", name);
}

void saveDept(String dept) {
  prefs.putString("dept", dept);
}