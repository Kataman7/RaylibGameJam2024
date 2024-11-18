#include "init.h"

#define SOURCE_PATH "."

Player player;
Camera2D camera;
TextureRec backgroundTexture;
ImageColors backgroundColors;
Vector2 vectorNull = {0, 0};
TextureRec texturePlayerIdle;
TextureRecAnimated texturePlayerRun;

void Init()
{
    SetTraceLogLevel(LOG_ALL);
    printf("Initialisation du jeu\n");
    player = CreatePlayer(50, 50);
    vectorNull = (Vector2){0, 0};
    camera = (Camera2D){0};
    camera.target = (Vector2) {player.hitBox.x, player.hitBox.y};
    camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;
    backgroundTexture = CreateTextureRec(SOURCE_PATH "/resources/bg.png");
    backgroundColors = CreateImageColors(SOURCE_PATH "/resources/bg.png");
    texturePlayerIdle = CreateTextureRec(SOURCE_PATH "/resources/player_idle.png");
    texturePlayerRun = CreateTextureRecAnimated(SOURCE_PATH "/resources/player_run", 5, 10);
}