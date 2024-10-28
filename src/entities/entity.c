#include "../core/init.h"

Entity CreateEntity(int x, int y, float velY, float velX, float weight, float friction)
{
    Entity entity;
    entity.hitBox = (Rectangle){x, y, 50, 50};
    entity.velY = velY;
    entity.velX = velX;
    entity.weight = weight;
    entity.friction = friction;
    return entity;
}

int EntityCollidesWithBackground(Entity entity)
{
    for (int i = 0; i < 4; i++)
    {
        Vector2 point = {entity.hitBox.x + (i % 2) * entity.hitBox.width, entity.hitBox.y + (i / 2) * entity.hitBox.height};
        Color color = backgroundColors.colors[(int)point.x + (int)point.y * backgroundColors.image.width];
        if (color.r == 0 && color.g == 0 && color.b == 0) return 1;
    }
    return 0;
}

