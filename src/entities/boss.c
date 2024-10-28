#include "../core/init.h"
#include "math.h"

Boss CreateBoss(int x, int y)
{
    Boss boss;
    boss.entity = CreateEntity(x, y, 0, 0, 0.5, 0.9);
    return boss;
}

void BossDashRight()
{
    boss.entity.velX += 20;
}

void BossDashLeft()
{
    boss.entity.velX -= 20;
}

void BossDash(Vector2 direction)
{
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }

    boss.entity.velX = direction.x * 20;
    boss.entity.velY = direction.y * 20;
}

void BossDashPlayer()
{
    BossDash((Vector2){player.entity.hitBox.x - boss.entity.hitBox.x, player.entity.hitBox.y - boss.entity.hitBox.y});
}

void BossDashCenter()
{
    BossDash((Vector2) {500, 100});
}

void runPatern()
{
    if (frameCount == 0)
    {
        BossDashRight();
    }
    else if (frameCount == 60 * 4)
    {
        BossDashLeft();
    }
    else if (frameCount == 60 * 7) 
    {
        BossDashPlayer();
    }
    else if (frameCount == 60 * 10)
    {
        BossDashCenter();
    }
    else if (frameCount == 60 * 13)
    {
        BossDashPlayer();
    }
}

void UpdateBoss()
{
    runPatern();

    float previousX = boss.entity.hitBox.x;
    float previousY = boss.entity.hitBox.y;

    boss.entity.hitBox.y += boss.entity.velY;
    boss.entity.velY *= boss.entity.friction;

    if (EntityCollidesWithBackground(boss.entity))
    {
        boss.entity.velY = 0;
        boss.entity.hitBox.y = previousY;
    }

    boss.entity.hitBox.x += boss.entity.velX;
    boss.entity.velX *= boss.entity.friction;

    if (EntityCollidesWithBackground(boss.entity))
    {
        boss.entity.velX = 0;
        boss.entity.hitBox.x = previousX;
    }
}