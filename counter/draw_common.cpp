#include "draw_screens.h"
#include "display.h"
#include "modes.h"
#include <math.h>

void drawBackButton() {
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.drawRoundRect(10, 5, 90, 30, 5, 0xFFFF);
  tft.setCursor(22, 12);
  tft.print("voltar");
}

void drawBackControl(int players) {
  if (players == 1) {
    drawBackButton();
  } else {
    int cx = tft.width() / 2;
    int cy = tft.height() / 2;
    uint16_t color = 0xFFFF;

    int outerR = 12;
    int innerR = 6;
    int toothLen = 6;

    // Corpo da engrenagem
    tft.fillCircle(cx, cy, outerR, color);
    tft.fillCircle(cx, cy, innerR, 0x0000);

    // Dentes quadrados (6)
    for (int i = 0; i < 6; i++) {
      float angle = i * 60.0 * 3.14159 / 180.0;
      int tx = cx + cos(angle) * (outerR + 1);
      int ty = cy + sin(angle) * (outerR + 1);

      // desenha o "quadradinho" do dente
      int w = 6, h = 6;
      for (int dx = -w/2; dx <= w/2; dx++) {
        for (int dy = -h/2; dy <= h/2; dy++) {
          int x = tx + dx;
          int y = ty + dy;
          tft.drawPixel(x, y, color);
        }
      }
    }

    // Furo no centro (eixo)
    tft.fillCircle(cx, cy, 2, 0x0000);
  }
}
