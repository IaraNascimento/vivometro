#ifndef DISPLAY_H
#define DISPLAY_H

#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>

extern MCUFRIEND_kbv tft;

uint16_t valueToColor(int val);

#endif
