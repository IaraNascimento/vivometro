#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawOne() {
  tft.fillScreen(0x0000);
  backTarget = 11;

  char buf[6];
  sprintf(buf, "%d", life[1][0]);

  tft.setFont();
  tft.setTextSize(10);
  tft.setTextColor(valueToColor(life[1][0]));

  int16_t bx, by;
  uint16_t bw, bh;
  tft.getTextBounds(buf, 0, 0, &bx, &by, &bw, &bh);

  int cx = tft.width() / 2;
  int cy = tft.height() / 2;
  int x = cx - bw / 2 - bx;
  int y = cy - bh / 2 - by;

  // --- número principal ---
  tft.setCursor(x, y);
  tft.print(buf);

  // --- botão "-" ---
  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(30, cy - 20);
  tft.print("-");

  // --- botão "+" ---
  tft.setCursor(tft.width() - 60, cy - 20);
  tft.print("+");

  // --- controle de retorno ---
  drawBackControl(1);
}
