#ifndef PLAYER_H
#define PLAYER_H

#include "../core/init.h"
#include "../world/tileMap.h"

typedef struct {
    Rectangle hitBox;
    TextureRec textureRec;
    float velY;
    float velX;
    float weight;
    int jumpMax;
    int jumpCount;
    int jumpForce;
    float speed;
    float friction;
} Player;

Player CreatePlayer(int x, int y);
int PlayerCollidesWithTile();
void UpdatePlayer();

#endif