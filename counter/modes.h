#ifndef MODES_H
#define MODES_H

extern int mode;
extern int backTarget;
extern int lifeBase;
extern int life[5][4];
extern int commanderDamage[4][4];
extern int activeCommander;
extern int poison[4];

void resetLifeBase(int lifeValue);
void handleModeFour(int x, int y);
void handleCMDFour(int x, int y);

#endif
