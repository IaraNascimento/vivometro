#include "draw_screens.h"
#include "modes.h"
#include "display.h"

void drawModeSelectLife() {
  tft.fillScreen(0x0000);

  // Bigger centered title
  tft.setTextSize(3);
  tft.setTextColor(tft.color565(195,135,255));

  const char* title1 = "valor inicial";
  const char* title2 = "de vida";
  int16_t bx,by;

  uint16_t bw,bh;
  tft.getTextBounds(title1,0,0,&bx,&by,&bw,&bh);
  int centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 40);
  tft.print(title1);

  tft.getTextBounds(title2,0,0,&bx,&by,&bw,&bh);
  centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 80);
  tft.print(title2);  

  // Buttons row
  int bwBtn = 80;  
  int bhBtn = 60;  
  int y = 160;      

  int x1 = 20;
  int x2 = x1 + bwBtn + 20;
  int x3 = x2 + bwBtn + 20;

  // Rounded thick borders
  tft.drawRoundRect(x1, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x2, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x3, y, bwBtn, bhBtn, 10, 0xFFFF);

  // Inside numbers centered
  tft.setTextSize(4);

  // Inside numbers colors
  tft.setTextColor(tft.color565(255,255,255));

  tft.setCursor(x1 + bwBtn/2 - 20, y + bhBtn/2 - 15);
  tft.print("20");

  tft.setCursor(x2 + bwBtn/2 - 20, y + bhBtn/2 - 15);
  tft.print("30");

  tft.setCursor(x3 + bwBtn/2 - 20, y + bhBtn/2 - 15);
  tft.print("40");
}

void drawBackControl(int players) {
  if (players == 1) {
    tft.setTextSize(2);
    tft.setTextColor(0xFFFF);
    tft.drawRoundRect(10, 5, 90, 30, 5, 0xFFFF);
    tft.setCursor(22, 12);
    tft.print("voltar");
  } else {
    int cx = tft.width()/2;
    int cy = tft.height()/2;
    tft.fillCircle(cx, cy, 10, 0xFFFF);
  }
}

void drawModeSelectPlayers(){
  tft.fillScreen(0x0000);

  // Bigger centered title
  tft.setTextSize(3);
  tft.setTextColor(tft.color565(195,135,255));

  const char* title1 = "quantidade de";
  const char* title2 = "jogadores";
  int16_t bx,by;

  uint16_t bw,bh;
  tft.getTextBounds(title1,0,0,&bx,&by,&bw,&bh);
  int centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 20);
  tft.print(title1);

  tft.getTextBounds(title2,0,0,&bx,&by,&bw,&bh);
  centerX = tft.width()/2 - (bw - 20)/2 - bx;
  tft.setCursor(centerX, 60);
  tft.print(title2);  

  // Buttons row
  int bwBtn = 80;  
  int bhBtn = 60;  
  int y = 120;      

  int x1 = 20;
  int x2 = x1 + bwBtn + 20;
  int x3 = x2 + bwBtn + 20;

  // Rounded thick borders
  tft.drawRoundRect(x1, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x2, y, bwBtn, bhBtn, 10, 0xFFFF);
  tft.drawRoundRect(x3, y, bwBtn, bhBtn, 10, 0xFFFF);

  // Inside numbers centered
  tft.setTextSize(4);

  // Inside numbers colors
  tft.setTextColor(tft.color565(255,255,255));

  tft.setCursor(x1 + bwBtn/2 - 10, y + bhBtn/2 - 15);
  tft.print("1");

  tft.setCursor(x2 + bwBtn/2 - 10, y + bhBtn/2 - 15);
  tft.print("2");

  tft.setCursor(x3 + bwBtn/2 - 10, y + bhBtn/2 - 15);
  tft.print("4");

  int bwVoltar = 100;
  int bhVoltar = 30;
  int voltarX = (tft.width() - bwVoltar) / 2;
  int voltarY = tft.height() - bhVoltar - 10;

  tft.drawRoundRect(voltarX, voltarY, bwVoltar, bhVoltar, 5, 0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(voltarX + 16, voltarY + 8);
  tft.print("voltar");
}

// -------- DRAW 1 COUNTER --------
void drawOne(){
  tft.fillScreen(0x0000);

  char buf[6];
  sprintf(buf, "%d", life[1][0]);

  tft.setFont();
  tft.setTextSize(10);
  tft.setTextColor(valueToColor(life[1][0]));

  int16_t bx,by; uint16_t bw,bh;
  tft.getTextBounds(buf,0,0,&bx,&by,&bw,&bh);

  int cx = tft.width()/2;
  int cy = tft.height()/2;
  int x = cx - bw/2 - bx;
  int y = cy - bh/2 - by;

  // number
  tft.setCursor(x,y);
  tft.print(buf);

  // minus on left
  tft.setTextSize(5);
  tft.setTextColor(0xFFFF);
  tft.setCursor(30, cy - 20);
  tft.print("-");

  // plus on right
  tft.setCursor(tft.width() - 60, cy - 20);
  tft.print("+");

  drawBackControl(1);
}

// -------- DRAW 2 COUNTERS --------
void drawTwo(){
  tft.fillScreen(0x0000);

  int midH = tft.height()/2;
  int cursorY = midH + midH/2 - 20;

  // --- TOP PLAYER ---
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

  // --- BOTTOM PLAYER ---
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

  drawBackControl(2);
}

// -------- DRAW 4 COUNTERS --------
void drawFour(){
  tft.fillScreen(0x0000);

  int w = tft.width()/2;
  int h = tft.height()/2;

  for(int i=0;i<4;i++){
    int quadrantRotation = (i == 0) ? 1 :
                           (i == 1) ? 3 :
                           (i == 2) ? 3 :
                                     1;
    tft.setRotation(quadrantRotation);

    int lifeVal = life[4][i];

    int cy = h + h/2;
    int cx = w/2;
    if(i == 0 || i == 2){
      cx = w + w/2;
    }

    if (activeCommander == -1 && i != activeCommander) {
      tft.setTextSize(5);
      tft.setTextColor(valueToColor(lifeVal));

      // calcula largura aproximada do texto
      int numDigits = (lifeVal < 10) ? 1 : (lifeVal < 100) ? 2 : (lifeVal < 1000) ? 3 : 4;
      int charWidth = 6 * 5; // 6px por caractere * textSize 5 = 30px
      int textWidth = numDigits * charWidth;

      // centraliza de forma dinâmica
      tft.setCursor(cx - textWidth/2, cy - 10);
      tft.print(lifeVal);
    }

    int pos_cx = w - 40;
    int neg_cx = 20;

    if(i == 1 || i == 3){
      pos_cx = w + pos_cx;
      neg_cx = w + neg_cx;
    }

    tft.setTextSize(4);
    tft.setTextColor(0xFFFF);
    tft.setCursor(neg_cx, cy-10);
    tft.print("-");
    tft.setCursor(pos_cx, cy-10);
    tft.print("+");

    if (activeCommander == -1) {
      tft.setTextSize(2);
      tft.setTextColor(tft.color565(100,100,100));
      tft.setCursor(neg_cx + 2, cy + 40);
      tft.print("comandante");
    }

    // Se estiver em modo comandante e esse não for o ativo
    if (activeCommander >= 0 && i != activeCommander) {
      int dmg = commanderDamage[activeCommander][i];
      tft.setTextSize(5);
      tft.setTextColor(tft.color565(255, 100, 255));

      // calcula largura aproximada do texto
      int numDigits = (dmg < 10) ? 1 : (dmg < 100) ? 2 : (dmg < 1000) ? 3 : 4;
      int charWidth = 6 * 5; // 6px por caractere * textSize 5 = 30px
      int textWidth = numDigits * charWidth;

      // centraliza de forma dinâmica
      tft.setCursor(cx - textWidth/2, cy - 10);
      tft.print(dmg);

    }
  }

  tft.setRotation(1);

  drawBackControl(4);
}
