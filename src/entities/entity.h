#ifndef ENTITY_H
#define ENTITY_H

#include "../core/init.h"

typedef struct {
    Rectangle hitBox;
    TextureRec textureRec;
    float velY;
    float velX;
    float weight;
    float friction;
    float speed;
} Entity;

Entity CreateEntity(int x, int y, float velY, float velX, float weight, float friction, float speed);
int EntityCollidesWithBackground(Entity entity);

#endif