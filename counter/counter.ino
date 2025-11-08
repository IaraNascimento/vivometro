#include "display.h"
#include "touch.h"
#include "modes.h"
#include "draw_screens.h"
#include "logic.h"

void setup() {
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  calibrateTouch();
  drawModeSelectLife();
}

void loop() {
  processTouch();
}
