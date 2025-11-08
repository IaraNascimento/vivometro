#include "touch.h"

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define TS_MINX 150
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int offsetX = 14;
int offsetY = -3;

// -------- CALIBRATE --------
void calibrateTouch() {
  tft.fillScreen(0x0000);
  tft.setTextColor(0xFFFF);
  tft.setTextSize(1);

  int pts = 3;
  int sx[3] = {50, tft.width() / 2, tft.width() - 50};
  int sy[3] = {50, tft.height() / 2, tft.height() - 50};
  long ox = 0, oy = 0;

  for (int i = 0; i < pts; i++) {
    tft.fillCircle(sx[i], sy[i], 5, 0xFFFF);
    tft.setCursor(20, 20);
    tft.print("Toque no ponto para calibrar");
    TSPoint p = {0, 0, 0};
    while (p.z < 10 || p.z > 1000) {
      p = ts.getPoint();
      pinMode(XM, OUTPUT); 
      pinMode(YP, OUTPUT);
    }
    int mx = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
    int my = map(p.x, TS_MINX, TS_MAXX, tft.height(), 0);
    ox += sx[i] - mx;
    oy += sy[i] - my;
    tft.fillCircle(sx[i], sy[i], 5, 0x0000);
    delay(200);
  }

  offsetX = ox / pts;
  offsetY = oy / pts;

  // --- MOSTRAR NA TELA ---
  tft.fillScreen(0x0000);
  tft.setCursor(20, 50);
  tft.setTextSize(2);
  tft.setTextColor(0x07E0); // Verde
  tft.print("OffsetX: ");
  tft.println(offsetX);
  tft.print("OffsetY: ");
  tft.println(offsetY);
}
