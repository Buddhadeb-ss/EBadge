#include "badge.h"
#include "display.h"
#include "storage.h"

void drawBadgeScreen() {
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(2, 2);
  display.println("<. > Point Blank");
  display.drawFastHLine(0, 12, 128, SH110X_WHITE);

  display.setTextSize(2);
  display.setCursor(2, 20);
  display.println(loadName());

  display.setTextSize(1);
  display.setCursor(2, 42);
  display.println(loadDept());

  display.setCursor(2, 56);
  display.println("Press MENU to Select");
}