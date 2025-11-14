#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawPoisonTwo() {
  tft.fillScreen(0x0000);
  backTarget = 12;

  int midH = tft.height() / 2;
  int cursorY = midH + midH / 2 - 1;
  int cursorX = 145;

  // --- jogador superior ---
  tft.setRotation(3);
  tft.setTextSize(5);
  tft.setTextColor(tft.color565(255, 100, 255));

  if (poison[1] >= 10) cursorX = 125;
  tft.setCursor(cursorX, cursorY);
  cursorX = 145;
  tft.print(poison[1]);

  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(tft.width() - 60, cursorY);
  tft.print("+");
  tft.setCursor(30, cursorY);
  tft.print("-");

  // --- jogador inferior ---
  tft.setRotation(1);
  tft.setTextSize(5);
  tft.setTextColor(tft.color565(255, 100, 255));
  if (poison[0] >= 10) cursorX = 125;
  tft.setCursor(cursorX, cursorY);
  cursorX = 145;
  tft.print(poison[0]);

  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(30, cursorY);
  tft.print("-");
  tft.setCursor(tft.width() - 60, cursorY);
  tft.print("+");

  // --- controle de retorno ---
  drawBackControl(2);
}
