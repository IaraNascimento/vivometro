#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleModeTwo(int x, int y) {
  int w = tft.width() / 2;
  int h = tft.height() / 2;
  int idx = (y < h) ? 0 : 1;

  if (abs(x - w) < 16 && abs(y - h) < 16) {
    mode = 2;
    drawModeSelectPlayers();
    return;
  }

  if (y < h) {
    if (x > w) life[2][idx]--;
    else life[2][idx]++;
  } else {
    if (x < w) life[2][idx]--;
    else life[2][idx]++;
  }

  drawTwo();
}
