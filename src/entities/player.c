#include "../core/init.h"

Player CreatePlayer(int x, int y)
{
    Player player;
    player.hitBox = (Rectangle){x, y, 50, 50};
    player.velY = 0;
    player.velX = 0;
    player.weight = 0.5;
    player.jumpMax = 2;
    player.jumpCount = 0;
    return player;
}

int PlayerCollidesWithTile()
{
    int blockX = player.hitBox.x / tileMap.tileSize;
    int blockY = player.hitBox.y / tileMap.tileSize;

    for (int y = blockY - 3; y < blockY + 3; y++)
    {
        for (int x = blockX - 3; x < blockX + 3; x++)
        {
            if (CheckCollisionRecs(player.hitBox, GetTile(tileMap, x, y).hitBox))
            {
                if (GetTile(tileMap, x, y).type == 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int PlayerCollidesWithBackground()
{
    // regarde si les 4 coin de la hitbox touche une couleur noir
    for (int i = 0; i < 4; i++)
    {
        Vector2 point = {player.hitBox.x + (i % 2) * player.hitBox.width, player.hitBox.y + (i / 2) * player.hitBox.height};
        Color color = backgroundColors.colors[(int)point.x + (int)point.y * backgroundColors.image.width];
        if (color.r == 0 && color.g == 0 && color.b == 0)
        {
            return 1;
        }
    }
    return 0;
}

void UpdatePlayer()
{
    float previousX = player.hitBox.x;
    float previousY = player.hitBox.y;

    player.velY += player.weight;
    player.hitBox.y += player.velY;

    if (PlayerCollidesWithBackground())
    {
        player.velY = - player.velY / 5;
        player.hitBox.y = previousY;
        player.jumpCount = 0;
    }

    player.hitBox.x += player.velX;
    player.velX *= 0.95;

    if (PlayerCollidesWithBackground())
    {
        player.velX = - player.velX / 5;
        player.hitBox.x = previousX;
    }
}