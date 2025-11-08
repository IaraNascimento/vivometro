#include "modes.h"

int mode = 0;
int lifeBase = 0;
int life[5][4] = {0};
int commanderDamage[4][4] = {0};
int activeCommander = -1;

void resetLifeBase(int lifeValue) {
  for (int m = 1; m <= 4; m++) {
    for (int p = 0; p < 4; p++) {
      life[m][p] = lifeValue;
    }
  }
}
