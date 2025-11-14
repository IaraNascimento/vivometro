#include "modes.h"

// -------- MODE --------
// 0 = calibrar, 1 = selecionar vida, 2 = selecionar jogadores,
// 11 = um contador, 12 = dois contadores, 14 = quatro contadores,
// 24 = dano de comandante para 4 jogadores
// 32 = dano de veneno para 2 jogadores
// 34 = dano de veneno para 4 jogadores
// 99 = menu

int mode = 1;
int backTarget = 11;
int lifeBase = 0;
int life[5][4] = {0};
int commanderDamage[4][4] = {0};
int activeCommander = -1; // -1 = modo normal, 0..3 = jogador em modo comandante
int poison[4] = {0, 0, 0, 0};

void resetLifeBase(int lifeValue) {
  // Resetar vidas
  for (int m = 1; m <= 4; m++) {
    for (int p = 0; p < 4; p++) {
      life[m][p] = lifeValue;
    }
  }

  // Resetar dano de comandante
  for (int atacante = 0; atacante < 4; atacante++) {
    for (int defensor = 0; defensor < 4; defensor++) {
      commanderDamage[atacante][defensor] = 0;
    }
  }

  // Resetar veneno
  for (int i = 0; i <= 3; i++) {
    poison[i] = 0;
  }

  // Sai do modo comandante se estiver ativo
  activeCommander = -1;
}

