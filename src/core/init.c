#include "init.h"

#define SOURCE_PATH "src"

Player player;
Camera2D camera;
TextureRec backgroundTexture;
ImageColors backgroundColors;
Vector2 vectorNull = {0, 0};
int seconds;
Boss boss;

void Init()
{
    SetTraceLogLevel(LOG_ALL);
    printf("Initialisation du jeu\n");

    player = CreatePlayer(1000, 500);
    vectorNull = (Vector2){0, 0};
    camera = (Camera2D){0};
    camera.target = (Vector2) {player.entity.hitBox.x, player.entity.hitBox.y};
    camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    backgroundTexture = CreateTextureRec(SOURCE_PATH "/resources/bg.png");
    backgroundColors = CreateImageColors(SOURCE_PATH "/resources/bg.png");
    seconds = 0;
    boss = CreateBoss(1000, 500);
}