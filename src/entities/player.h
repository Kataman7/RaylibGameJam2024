#ifndef PLAYER_H
#define PLAYER_H

#include "../core/init.h"

typedef struct {
    Entity entity;
    int speed;
    int jumpMax;
    int jumpCount;
    int jumpForce;
    TextureRec textureRec;
} Player;

Player CreatePlayer(int x, int y);
void UpdatePlayer();

#endif