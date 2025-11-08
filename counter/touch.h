#ifndef TOUCH_H
#define TOUCH_H

#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

extern MCUFRIEND_kbv tft;
extern TouchScreen ts;
extern int mode;
extern int lifeBase;
extern int life[5][4];
extern int commanderDamage[4][4];
extern int activeCommander;
extern int offsetX;
extern int offsetY;

void processTouch();

#endif
