#ifndef INIT_H
#define INIT_H

#include "raylib.h"
#include "render.h"
#include "../entities/entity.h"
#include "../entities/player.h"
#include "../entities/boss.h"
#include "input.h"
#include "game.h"
#include "stdio.h"
#include "stdlib.h"

extern Player player;
extern Vector2 vectorNull;
extern Camera2D camera;
extern TextureRec backgroundTexture;
extern ImageColors backgroundColors;
extern long int frameCount;
extern Boss boss;
extern TextureRecAnimated texturePlayerIdle;

void Init();

#endif