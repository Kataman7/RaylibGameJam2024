#include "player.h"

Player createPlayer(int x, int y)
{
    Player player;
    player.hitBox = (Rectangle){x, y, 50, 50};
    player.velY = 0;
    player.velX = 0;
    player.weight = 0.5;
    return player;
}

int playerCollidesWithTile(Player player, TileMap tileMap)
{
    int blockX = player.hitBox.x / tileMap.tileSize;
    int blockY = player.hitBox.y / tileMap.tileSize;

    for (int y = blockY - 3; y < blockY + 3; y++)
    {
        for (int x = blockX - 3; x < blockX + 3; x++)
        {
            if (CheckCollisionRecs(player.hitBox, getTile(tileMap, x, y).hitBox))
            {
                if (getTile(tileMap, x, y).type == 1)
                {
                    return 1;
                }
            }
        }
    }
}

void updatePlayer(Player *player, TileMap tileMap)
{
    float previousX = player->hitBox.x;
    float previousY = player->hitBox.y;

    player->hitBox.x += player->velY;
    player->velY *= player->weight;

    if (playerCollidesWithTile(*player, tileMap))
    {
        player->velY = 0;
        player->hitBox.x = previousX;
    }

    player->hitBox.x += player->velX;
    player->velX *= 0.95;

    if (playerCollidesWithTile(*player, tileMap))
    {
        player->velX = 0;
        player->hitBox.x = previousX;
    }
}