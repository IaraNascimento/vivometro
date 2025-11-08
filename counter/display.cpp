#include "display.h"

MCUFRIEND_kbv tft;

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
