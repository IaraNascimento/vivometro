#include "modes.h"

// -------- MODE --------
// 0 = calibrar, 1 = selecionar vida, 2 = selecionar jogadores,
// 3 = um contador, 4 = dois contadores, 5 = quatro contadores
int mode = 1;
int lifeBase = 0;
int life[5][4] = {0};
int commanderDamage[4][4] = {0};
int activeCommander = -1; // -1 = modo normal, 0..3 = jogador em modo comandante

void resetLifeBase(int lifeValue) {
  for (int m = 1; m <= 4; m++) {
    for (int p = 0; p < 4; p++) {
      life[m][p] = lifeValue;
    }
  }
}
