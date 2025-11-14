#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleModeSelectPlayers(int x, int y) {
  if (y > 200) {
    mode = 1;
    drawModeSelectLife();
    return;
  }

  if (y > 120 && y < 180) {
    if (x > 20 && x < 100) {
      mode = 11;
      drawOne();
    } else if (x > 120 && x < 200) {
      mode = 12;
      drawTwo();
    } else if (x > 220 && x < 300) {
      mode = 14;
      drawFour();
    }
  }
}
