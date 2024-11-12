#ifndef PLAYER_H
#define PLAYER_H

#include "init.h"

typedef struct {
    Rectangle hitBox;
    TextureRec* textureRec;
    double velY;
    double velX;
    float weight;
    float friction;
    float speed;
    int jumpCount;
    int jumpMax;
    float jumpForce;
} Player;

Player CreatePlayer(int x, int y);
void UpdatePlayer();
int PlayerCollidesWithBackground();

#endif