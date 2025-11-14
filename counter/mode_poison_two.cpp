#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handlePoisonTwo(int x, int y) {
  int w = tft.width() / 2;
  int h = tft.height() / 2;

  // --- Clicar no centro: volta ao modo anterior ---
  if (abs(x - w) < 20 && abs(y - h) < 20) {
    mode = 12; // volta para modo 2 jogadores
    drawTwo();
    return;
  }

  // --- Jogador 1 (inferior) ---
  if (y > h) {
    if (x < w) {
      // diminuir
      if (poison[0] > 0) poison[0]--;
    } else {
      // aumentar
      poison[0]++;
    }
    drawPoisonTwo();
    return;
  }

  // --- Jogador 2 (superior) ---
  if (y < h) {
    if (x < w) {
      // aumentar
      poison[1]++;
    } else {
      // diminuir
      if (poison[1] > 0) poison[1]--;
    }
    drawPoisonTwo();
    return;
  }

  return;
}
