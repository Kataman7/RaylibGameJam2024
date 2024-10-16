#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "tileMap.h"

typedef struct {
    Rectangle hitBox;
    float velY;
    float velX;
    float weight;
} Player;


#endif