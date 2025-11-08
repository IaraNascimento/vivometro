#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

void handleModeFour(int x, int y) {
  int w = tft.width() / 2;
  int h = tft.height() / 2;

  // --- CLICAR NO CENTRO: volta ao modo anterior ou sai do modo comandante ---
  if (abs(x - w) < 16 && abs(y - h) < 16) {
    if (activeCommander == -1) {
      mode = 2;
      drawModeSelectPlayers();
      return;
    } else {
      activeCommander = -1;
      drawFour();
      return;
    }
  }

  // --- Determinar quadrante tocado ---
  int quadrant = -1;
  if (x > w && y > h) quadrant = 0; // inferior direito
  if (x > w && y < h) quadrant = 1; // superior direito
  if (x < w && y < h) quadrant = 2; // superior esquerdo
  if (x < w && y > h) quadrant = 3; // inferior esquerdo
  if (quadrant < 0) return;

  // --- Clique no botão "comandante" ---
  if ((activeCommander == -1) && (y > h+h/2+25 || y < h-h/2-25)) {
    activeCommander = (activeCommander == quadrant) ? -1 : quadrant;
    drawFour();
    return;
  }

  // --- Modo normal (sem comandante ativo) ---
  if (activeCommander == -1) {
    if (x > w && y > h) {
      if (x < (w + w / 2)) life[4][0]--;
      else life[4][0]++;
    }
    if (x > w && y < h) {
      if (x > (w + w / 2)) life[4][1]--;
      else life[4][1]++;
    }
    if (x < w && y < h) {
      if (x > w / 2) life[4][2]--;
      else life[4][2]++;
    }
    if (x < w && y > h) {
      if (x < w / 2) life[4][3]--;
      else life[4][3]++;
    }
    drawFour();
    return;
  }

  // --- Modo comandante: alterar dano de comandante ---
  if (quadrant != activeCommander) {
    int receiver = activeCommander;
    int attacker = quadrant;

    if (x > w && y > h) {
      if (x < (w + w / 2)) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      }
      else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x > w && y < h) {
      if (x > (w + w / 2)) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      }
      else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x < w && y < h) {
      if (x > w / 2) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      }
      else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    if (x < w && y > h) {
      if (x < w / 2) {
        if (commanderDamage[receiver][attacker] > 0) {
          commanderDamage[receiver][attacker]--;
          life[4][receiver]++;
        }
      }
      else {
        commanderDamage[receiver][attacker]++;
        life[4][receiver]--;
      }
    }

    drawFour();
    return;
  }

  return;
}