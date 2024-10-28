#include "../core/init.h"

Boss CreateBoss(int x, int y)
{
    Boss boss;
    boss.entity = CreateEntity(x, y, 0, 0, 0.5, 0.9, 5);
    return boss;
}

void runPatern()
{
    if (seconds == 0)
    {
        boss.entity.velX += 5;
    }
    else if (seconds == 4)
    {
        boss.entity.velY -= 5;
    }
    else if (seconds == 7 || seconds == 9 || seconds == 10) 
    {
        boss.entity.velY += 1;
        boss.entity.velX += 1;
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