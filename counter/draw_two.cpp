#include "draw_screens.h"
#include "display.h"
#include "modes.h"

void drawTwo() {
  tft.fillScreen(0x0000);
  backTarget = 12;

  int midH = tft.height() / 2;
  int cursorY = midH + midH / 2 - 20;

  // --- jogador superior ---
  tft.setRotation(3);
  tft.setTextSize(8);
  tft.setTextColor(valueToColor(life[2][0]));
  tft.setCursor(120, cursorY);
  tft.print(life[2][0]);

  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(tft.width() - 60, cursorY);
  tft.print("+");
  tft.setCursor(30, cursorY);
  tft.print("-");

  // --- jogador inferior ---
  tft.setRotation(1);
  tft.setTextSize(8);
  tft.setTextColor(valueToColor(life[2][1]));
  tft.setCursor(120, cursorY);
  tft.print(life[2][1]);

  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(30, cursorY);
  tft.print("-");
  tft.setCursor(tft.width() - 60, cursorY);
  tft.print("+");

  // --- controle de retorno ---
  drawBackControl(2);
}
