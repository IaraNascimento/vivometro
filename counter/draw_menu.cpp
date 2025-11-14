#include "draw_screens.h"
#include "display.h"

void drawMenu() {
  tft.fillScreen(0x0000);

  // ----- botão "voltar" -----
  drawBackButton();

  // ----- texto central -----
  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);
  tft.setCursor(10, 75);
  tft.print("Clique em");

  tft.setTextColor(0x001F); // azul
  tft.setCursor(10, 100);
  tft.print("CMD");

  tft.setTextColor(0xFFFF);
  tft.setCursor(55, 100);
  tft.print("abaixo");

  tft.setCursor(10, 125);
  tft.print("da vida");

  tft.setCursor(10, 150);
  tft.print("para marcar");

  tft.setCursor(10, 175);
  tft.print("dano de");

  tft.setTextColor(0x001F); // azul
  tft.setCursor(10, 200);
  tft.print("comandante");

  // ----- botões à direita -----
  int x = 160; // posição horizontal dos botões
  int y = 45;  // posição inicial vertical
  int w = 140; // largura
  int h = 40;  // altura
  int gap = 20; // espaçamento entre eles

  const char* labels[] = {
    " reiniciar",
    "  veneno",
    " n jogador"
  };

  tft.setTextSize(2);
  tft.setTextColor(0xFFFF);

  for (int i = 0; i < 3; i++) {
    int by = y + i * (h + gap);
    tft.drawRoundRect(x + 3, by - 3, w, h, 5, 0xFFFF);

    int textX = x + 8;
    int textY = by + 10;
    tft.setCursor(textX, textY);
    tft.print(labels[i]);
  }
}
