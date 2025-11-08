#ifndef TOUCH_H
#define TOUCH_H

#include <TouchScreen.h>
#include "display.h"
#include "modes.h"

extern TouchScreen ts;
extern int offsetX;
extern int offsetY;

void calibrateTouch();

#endif
