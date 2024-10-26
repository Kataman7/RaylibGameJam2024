#ifndef INIT_H
#define INIT_H

#include "raylib.h"
#include "render.h"
#include "../entities/player.h"
#include "../world/tileMap.h"
#include "input.h"
#include "game.h"
#include "stdio.h"
#include "stdlib.h"

extern Player player;
extern TileMap tileMap;
extern Vector2 vectorNull;
extern Camera2D camera;
extern TextureRec backgroundTexture;
extern ImageColors backgroundColors;

void Init();

#endif