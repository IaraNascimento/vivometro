#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include <TouchScreen.h>

MCUFRIEND_kbv tft;

#define YP A3
#define XM A2
#define YM 9
#define XP 8

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define TS_MINX 150
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

int offsetX = 0;
int offsetY = 0;

// -------- MODE --------
// 0 = calibrar, 1 = selecionar vida, 2 = selecionar jogadores,
// 3 = um contador, 4 = dois contadores, 5 = quatro contadores
int mode = 0;
int lifeBase = 0;
int life[5][4] = {0};
int commanderDamage[4][4] = {0};
int activeCommander = -1; // -1 = modo normal, 0..3 = jogador em modo comandante

// -------- COLOR PROGRESS --------
uint16_t valueToColor(int val) {
  if (val < 4) return tft.color565(255, 0, 0);
  if (val <= 14) {
    float r = (float)(val-4)/10.0;
    return tft.color565(255, (uint8_t)(r*200), 0);
  }
  if (val <= 29) return tft.color565(255,255,0);
  if (val <= 40) return tft.color565(0,255,0);
  return tft.color565(0,0,255);
}

// -------- BACK CONTROL --------
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

// -------- DRAW MODE SELECT LIFE AMOUNT --------
void drawModeSelectLife(){
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

// -------- DRAW MODE SELECT PLAYERS --------
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

// -------- CALIBRATE --------
void calibrateTouch(){
  tft.fillScreen(0x0000);
  tft.setTextColor(0xFFFF);
  tft.setTextSize(1);

  int pts = 3;
  int sx[3]={50,tft.width()/2,tft.width()-50};
  int sy[3]={50,tft.height()/2,tft.height()-50};
  long ox=0,oy=0;

  for(int i=0;i<pts;i++){
    tft.fillCircle(sx[i],sy[i],5,0xFFFF);
    tft.setCursor(20,20);
    tft.print("Toque no ponto para calibrar");
    TSPoint p={0,0,0};
    while(p.z<10 || p.z>1000){
      p=ts.getPoint();
      pinMode(XM,OUTPUT); pinMode(YP,OUTPUT);
    }
    int mx = map(p.y,TS_MINY,TS_MAXY,0,tft.width());
    int my = map(p.x,TS_MINX,TS_MAXX,tft.height(),0);
    ox += sx[i]-mx;
    oy += sy[i]-my;
    tft.fillCircle(sx[i],sy[i],5,0x0000);
    delay(200);
  }
  offsetX = ox/pts;
  offsetY = oy/pts;

  mode = 1;
}

// -------- RESET LIFE VALUE --------
void resetLifeBase(int lifeValue) {
  life[1][0] = lifeValue;
  life[2][0] = lifeValue;
  life[2][1] = lifeValue;
  life[4][0] = lifeValue;
  life[4][1] = lifeValue;
  life[4][2] = lifeValue;
  life[4][3] = lifeValue;
}

// -------- SETUP --------
void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  calibrateTouch();
  drawModeSelectLife();
}

// -------- LOOP --------
void loop() {
  TSPoint p = ts.getPoint();
  pinMode(XM,OUTPUT);
  pinMode(YP,OUTPUT);

  if (p.z > 10 && p.z < 1000) {
    int x = map(p.y,TS_MINY,TS_MAXY,0,tft.width())+offsetX;
    int y = map(p.x,TS_MINX,TS_MAXX,tft.height(),0)+offsetY;

    // MODE SELECT LIFE
    if ( mode == 1 ) {
      if (y > 160 && y < 220) {
        if (x > 20 && x < 100) {
          lifeBase = 20;
          mode = 2;
          resetLifeBase(lifeBase);
          drawModeSelectPlayers();
          return;
        } else if (x > 120 && x < 200) {
          lifeBase = 30;
          mode = 2;
          resetLifeBase(lifeBase);
          drawModeSelectPlayers();
          return;
        } else if (x > 220 && x < 300) {
          lifeBase = 40;
          mode = 2;
          resetLifeBase(lifeBase);
          drawModeSelectPlayers();
          return;
        }
      }
      return;
    }

    // MODE SELECT PLAYERS
    if ( mode == 2 ) {
      
      if (y > 200) {
        mode = 1;
        drawModeSelectLife();
        return;
      }

      if (y > 120 && y < 180) {
        if (x > 20 && x < 100) {
          mode = 3;
          drawOne();
          return;
        }
        if (x > 120 && x < 200) {
          mode = 4;
          drawTwo();
          return;
        }
        if (x > 220 && x < 300) {
          mode = 5;
          drawFour();
          return;
        }
      }
      return;
    }

    if ( mode == 3 ) {
      if(y > 5 && y < 35 && x > 10 && x < 90) { 
        mode = 2; 
        drawModeSelectPlayers(); 
        return; 
      }
  
      if(x < tft.width()/2) life[1][0]--;
      else life[1][0]++;

      drawOne();
      return;
    }

    if ( mode == 4 ) {
      int w = tft.width()/2;
      int h = tft.height()/2;
      int idx = (y<h)?0:1;

      if(abs(x - w) < 16 && abs(y - h) < 16) {
        mode = 2;
        drawModeSelectPlayers();
        return;
      }

      if(y < h){
        if(x > w) life[2][idx]--;
        else life[2][idx]++;
      } else {
        if(x < w) life[2][idx]--;
        else life[2][idx]++;
      }

      drawTwo();
      return;
    }

    if (mode == 5) {
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
  }
}
