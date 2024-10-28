#ifndef BOSS_H
#define BOSS_H

#include "../core/init.h"

typedef struct {
    Entity entity;
    TextureRec textureRec;
} Boss;

Boss CreateBoss(int x, int y);
void UpdateBoss();

#endif