#include "modes.h"
#include "draw_screens.h"
#include "display.h"

void handleMenu(int x, int y, int backTarget) {
  // ----- botão "voltar" -----
  if (y > 5 && y < 35 && x > 10 && x < 90) {
    mode = backTarget;
    if (backTarget == 12) drawTwo();
    if (backTarget == 14) drawFour();
    return;
  }

  // ----- botões da direita -----
  int bx = 160;
  int by = 45;
  int bw = 140;
  int bh = 40;
  int gap = 20;

  // reiniciar partida
  if (x > bx && x < bx + bw && y > by && y < by + bh) {
    resetLifeBase(lifeBase);
    mode = backTarget;
    if (mode == 12) drawTwo();
    if (mode == 14) drawFour();
    return;
  }

  // marcar veneno
  if (x > bx && x < bx + bw && y > by + (bh + gap) && y < by + (bh + gap) + bh) {
    mode = backTarget + 20;
    if (mode == 32) drawPoisonTwo();
    if (mode == 34) drawPoisonFour();
    return;
  }

  // volta selecao de jogadores
  if (x > bx && x < bx + bw && y > by + 2 * (bh + gap) && y < by + 2 * (bh + gap) + bh) {
    mode = 2; // tela de seleção de jogadores
    drawModeSelectPlayers();
    return;
  }

  return;
}
