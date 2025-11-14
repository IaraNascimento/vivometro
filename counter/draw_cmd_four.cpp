#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawCMDFour() {
  tft.fillScreen(0x0000);

  int w = tft.width() / 2;
  int h = tft.height() / 2;

  for (int i = 0; i < 4; i++) {
    int quadrantRotation = (i == 0) ? 1 :
                           (i == 1) ? 3 :
                           (i == 2) ? 3 : 1;
    tft.setRotation(quadrantRotation);

    int cy = h + h / 2;
    int cx = w / 2;

    if (i == 0 || i == 2) cx = w + w / 2;

    // --- botões + e - ---
    int pos_cx = cx + 40;
    int neg_cx = cx - 60;

    // if (i == 1 || i == 3) {
    //   pos_cx = w + pos_cx;
    //   neg_cx = w + neg_cx;
    // }

    tft.setTextSize(4);
    tft.setTextColor(0xFFFF);

    if (activeCommander >= 0 && i != activeCommander) {
      tft.setCursor(neg_cx, cy - 10);
      tft.print("-");
      tft.setCursor(pos_cx, cy - 10);
      tft.print("+");
    }

    // --- dano de comandante ---
    if (activeCommander >= 0 && i != activeCommander) {
      int dmg = commanderDamage[activeCommander][i];
      tft.setTextSize(5);
      tft.setTextColor(tft.color565(255, 100, 255));

      int numDigits = (dmg < 10) ? 1 : (dmg < 100) ? 2 :
                      (dmg < 1000) ? 3 : 4;
      int charWidth = 6 * 5;
      int textWidth = numDigits * charWidth;

      tft.setCursor(cx - textWidth / 2, cy - 10);
      tft.print(dmg);
    }
  }

  tft.setRotation(1);
  drawBackControl(4);
}
