#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleModeSelectLife(int x, int y) {
  if (y > 160 && y < 220) {
    if (x > 20 && x < 100) {
      lifeBase = 20;
    } else if (x > 120 && x < 200) {
      lifeBase = 30;
    } else if (x > 220 && x < 300) {
      lifeBase = 40;
    } else return;

    mode = 2;
    resetLifeBase(lifeBase);
    drawModeSelectPlayers();
  }
}
