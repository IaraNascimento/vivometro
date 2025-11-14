#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawModeSelectLife() {
  tft.fillScreen(0x0000);
  tft.setTextSize(3);
  tft.setTextColor(tft.color565(195,135,255));

  const char* title1 = "valor inicial";
  const char* title2 = "de vida";
  int16_t bx, by;
  uint16_t bw, bh;

  tft.getTextBounds(title1, 0, 0, &bx, &by, &bw, &bh);
  int centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 40);
  tft.print(title1);

  tft.getTextBounds(title2, 0, 0, &bx, &by, &bw, &bh);
  centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 80);
  tft.print(title2);

  int bwBtn = 80, bhBtn = 60, y = 160;
  int x1 = 20, x2 = x1 + bwBtn + 20, x3 = x2 + bwBtn + 20;

  tft.drawRoundRect(x1, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x2, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x3, y, bwBtn, bhBtn, 10, 0xFFFF);

  tft.setTextSize(4);
  tft.setTextColor(tft.color565(255,255,255));

  tft.setCursor(x1 + bwBtn/2 - 20, y + bhBtn/2 - 15); tft.print("20");
  tft.setCursor(x2 + bwBtn/2 - 20, y + bhBtn/2 - 15); tft.print("30");
  tft.setCursor(x3 + bwBtn/2 - 20, y + bhBtn/2 - 15); tft.print("40");
}
