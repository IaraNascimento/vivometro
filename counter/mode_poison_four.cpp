#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handlePoisonFour(int x, int y) {
  int w = tft.width() / 2;
  int h = tft.height() / 2;

  // --- Clicar no centro: volta ao modo anterior ---
  if (abs(x - w) < 16 && abs(y - h) < 16) {
    mode = 14; // volta para modo 4 jogadores
    drawFour();
    return;
  }

  // --- Determinar quadrante tocado ---
  int quadrant = -1;
  if (x > w && y > h) quadrant = 0; // inferior direito
  if (x > w && y < h) quadrant = 1; // superior direito
  if (x < w && y < h) quadrant = 2; // superior esquerdo
  if (x < w && y > h) quadrant = 3; // inferior esquerdo
  if (quadrant < 0) return;

  // --- Ajustar contador de veneno ---
  if (x < w / 2 || x > (w + w / 2)) {
    // diminuir
    if (poison[quadrant] > 0) poison[quadrant]--;
  } else {
    // aumentar
    poison[quadrant]++;
  }

  drawPoisonFour();
}
