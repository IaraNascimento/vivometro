#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawFour() {
  tft.fillScreen(0x0000);
  backTarget = 14;

  int w = tft.width() / 2;
  int h = tft.height() / 2;

  for (int i = 0; i < 4; i++) {
    int quadrantRotation = (i == 0) ? 1 :
                           (i == 1) ? 3 :
                           (i == 2) ? 3 : 1;
    tft.setRotation(quadrantRotation);

    int lifeVal = life[4][i];
    int cy = h + h / 2;
    int cx = w / 2;

    if (i == 0 || i == 2) cx = w + w / 2;

    // --- número de vida ---
    if (activeCommander == -1 && i != activeCommander) {
      tft.setTextSize(5);
      tft.setTextColor(valueToColor(lifeVal));

      int numDigits = (lifeVal < 10) ? 1 : (lifeVal < 100) ? 2 :
                      (lifeVal < 1000) ? 3 : 4;
      int charWidth = 6 * 5; // 6px * textSize 5 = 30px
      int textWidth = numDigits * charWidth;

      tft.setCursor(cx - textWidth / 2, cy - 25);
      tft.print(lifeVal);
    }

    // --- botões + e - ---
    int pos_cx = w - 40;
    int neg_cx = 20;

    if (i == 1 || i == 3) {
      pos_cx = w + pos_cx;
      neg_cx = w + neg_cx;
    }

    tft.setTextSize(4);
    tft.setTextColor(0xFFFF);
    tft.setCursor(neg_cx, cy - 25);
    tft.print("-");
    tft.setCursor(pos_cx, cy - 25);
    tft.print("+");

    // --- rótulo "comandante" ---
    if (activeCommander == -1) {
      tft.setTextSize(2);
      tft.setTextColor(tft.color565(125,125,125));
      tft.setCursor(neg_cx + 40, cy + 35);
      tft.print("CMD");
    }
  }

  tft.setRotation(1);
  drawBackControl(4);
}
