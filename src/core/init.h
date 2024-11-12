#ifndef INIT_H
#define INIT_H

#include "raylib.h"
#include "render.h"
#include "player.h"
#include "input.h"
#include "game.h"
#include "stdio.h"
#include "stdlib.h"

extern Player player;
extern Vector2 vectorNull;
extern Camera2D camera;
extern TextureRec backgroundTexture;
extern ImageColors backgroundColors;
extern TextureRec texturePlayerIdle;
extern TextureRecAnimated texturePlayerRun;

void Init();

#endif