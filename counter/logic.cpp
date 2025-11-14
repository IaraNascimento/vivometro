#include "touch.h"
#include "logic.h"
#include "display.h"
#include "draw_screens.h"

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define TS_MINX 150
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

// Declaração das funções específicas de cada modo
void handleModeSelectLife(int x, int y);
void handleModeSelectPlayers(int x, int y);
void handleModeOne(int x, int y);
void handleModeTwo(int x, int y);
void handleModeFour(int x, int y);
void handleCMDFour(int x, int y);
void handlePoisonTwo(int x, int y);
void handlePoisonFour(int x, int y);
void handleMenu(int x, int y, int backTarget);

void processTouch() {
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > 10 && p.z < 1000) {
    int x = map(p.y, TS_MINY, TS_MAXY, 0, tft.width()) + offsetX;
    int y = map(p.x, TS_MINX, TS_MAXX, tft.height(), 0) + offsetY;

    switch (mode) {
      // case 0: calibrar
      case 1: handleModeSelectLife(x, y); break;
      case 2: handleModeSelectPlayers(x, y); break;
      case 11: handleModeOne(x, y); break;
      case 12: handleModeTwo(x, y); break;
      case 14: handleModeFour(x, y); break;
      case 24: handleCMDFour(x, y); break;
      case 32: handlePoisonTwo(x, y); break;
      // case 34: handlePoisonFour(x, y); break;
      case 99: handleMenu(x, y, backTarget); break;
    }
  }
}
