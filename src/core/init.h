#ifndef INIT_H
#define INIT_H
//Fonctions d'initialisation (fenêtre, ressources, etc.)
#include "../entities/player.h";
#include "../world/tileMap.h";
#include "render.h";
#include "raylib.h";

extern Player player;
extern TileMap tileMap;
extern Vector2 vectorNull;
extern Camera2D camera;

#endif