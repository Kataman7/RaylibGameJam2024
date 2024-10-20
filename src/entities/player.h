#ifndef PLAYER_H
#define PLAYER_H

#include "../core/init.h"

typedef struct {
    Rectangle hitBox;
    TextureRec textureRec;
    float velY;
    float velX;
    float weight;
} Player;

Player createPlayer(int x, int y);
int playerCollidesWithTile(Player player, TileMap tileMap);
void updatePlayer(Player *player, TileMap tileMap);

#endif