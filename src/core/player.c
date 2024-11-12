#include "init.h"
#include "math.h"

Player CreatePlayer(int x, int y)
{
    Player newPlayer = (Player){0};
    newPlayer.hitBox = (Rectangle){x, y, 8*5, 8*5};
    newPlayer.velY = 0.0f;
    newPlayer.velX = 0.0f;
    newPlayer.weight = 0.4f;
    newPlayer.friction = 0.75f;
    newPlayer.jumpMax = 2;
    newPlayer.jumpCount = 0;
    newPlayer.jumpForce = 4.0f * 2;
    newPlayer.speed = 0.4f * 3;
    newPlayer.textureRec = &texturePlayerRun.textureRec;
    return newPlayer;
}

int PlayerCollidesWithBackground()
{
    for (int i = 0; i < 4; i++)
    {
        Vector2 point = {player.hitBox.x + (i % 2) * player.hitBox.width, player.hitBox.y + (i / 2) * player.hitBox.height};
        if (point.x < 0 || point.x >= backgroundColors.image.width || point.y < 0 || point.y >= backgroundColors.image.height) continue;
        Color color = backgroundColors.colors[(int)point.x + (int)point.y * backgroundColors.image.width];
        if (color.r == 255 && color.g == 255 && color.b == 255) return 1;
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
        player.velY = 0;
        player.hitBox.y = previousY;
        player.jumpCount = 0;
    }

    player.hitBox.x += player.velX;
    player.velX *= player.friction;

    if (PlayerCollidesWithBackground())
    {
        player.velX = 0;
        player.hitBox.x = previousX;
    }

    if (fabs(player.velX) < 0.01f) {
        player.velX = 0.0f;
    }


    if (player.velX != 0)
    {
        player.textureRec = &texturePlayerRun.textureRec;
        if (player.velX < 0)
        {
            player.textureRec->sourceRec = (Rectangle){0, 0, -player.textureRec->texture.width, player.textureRec->texture.height};
        }
        else if (player.velX > 0)
        {
            player.textureRec->sourceRec = (Rectangle){0, 0, player.textureRec->texture.width, player.textureRec->texture.height};
        }
    }
    else
    {
        int direction = player.textureRec->sourceRec.width > 0 ? 1 : -1;
        player.textureRec = &texturePlayerIdle;
        player.textureRec->sourceRec = (Rectangle){0, 0, direction * player.textureRec->texture.width, player.textureRec->texture.height};
    }

}