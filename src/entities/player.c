#include "../core/init.h"

Player CreatePlayer(int x, int y)
{
    Player player;
    player.entity = CreateEntity(x, y, 0, 0, 0.5, 0.9);
    player.jumpMax = 2;
    player.jumpCount = 0;
    player.jumpForce = 20;
    player.speed = 2;
    return player;
}

void UpdatePlayer()
{
    float previousX = player.entity.hitBox.x;
    float previousY = player.entity.hitBox.y;

    player.entity.velY += player.entity.weight;
    player.entity.hitBox.y += player.entity.velY;

    if (EntityCollidesWithBackground(player.entity))
    {
        player.entity.velY = 0;
        player.entity.hitBox.y = previousY;
        player.jumpCount = 0;
    }

    player.entity.hitBox.x += player.entity.velX;
    player.entity.velX *= player.entity.friction;

    if (EntityCollidesWithBackground(player.entity))
    {
        player.entity.velX = 0;
        player.entity.hitBox.x = previousX;
    }
}