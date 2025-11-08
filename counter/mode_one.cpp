#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleModeOne(int x, int y) {
  if (y > 5 && y < 35 && x > 10 && x < 90) {
    mode = 2;
    drawModeSelectPlayers();
    return;
  }

  if (x < tft.width() / 2) life[1][0]--;
  else life[1][0]++;

  drawOne();
}
