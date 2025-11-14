#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleCMDFour(int x, int y) {
  int w = tft.width() / 2;
  int h = tft.height() / 2;

  int quadrant = -1;
  if (x > w && y > h) quadrant = 0;
  if (x > w && y < h) quadrant = 1;
  if (x < w && y < h) quadrant = 2;
  if (x < w && y > h) quadrant = 3;
  if (quadrant < 0) return;

  // --- Modo comandante: alterar dano de comandante ---
  if (quadrant != activeCommander) {
    int receiver = activeCommander;
    int attacker = quadrant;

    // Cada quadrante controla o dano de comandante com base na direção do toque
    if (x > w && y > h) { // inferior direito
      if (x < (w + w / 2)) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      } else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x > w && y < h) { // superior direito
      if (x > (w + w / 2)) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      } else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x < w && y < h) { // superior esquerdo
      if (x > w / 2) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      } else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x < w && y > h) { // inferior esquerdo
      if (x < w / 2) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      } else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    drawCMDFour();
  }
}
