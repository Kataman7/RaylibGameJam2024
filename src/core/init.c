#include "init.h"

void init()
{
    player = createPlayer(100, 100);
    tileMap = createTileMap(20, 20, 50);
    vectorNull = (Vector2){0, 0};
    camera = (Camera2D){0, {player.hitBox.x, player.hitBox.y}};
}