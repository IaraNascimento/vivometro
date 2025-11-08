#include "logic.h"
#include "display.h"
#include "draw_screens.h"
#include "touch.h"

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define TS_MINX 150
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

void processTouch() {
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
