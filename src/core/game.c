//Logique du jeu (mises à jour, interactions, etc.)
#include "init.h"

int frameCounter = 0;

void UpdateGame()
{
    camera.target = (Vector2){player.entity.hitBox.x, player.entity.hitBox.y};
    UpdatePlayer();
    UpdateInput();

    frameCounter++;
    if (frameCounter >= 60)
    {
        seconds++;
        frameCounter = 0;
    }
    UpdateBoss();
}

void DrawGame()
{
    DrawTextureRec(backgroundTexture.texture, backgroundTexture.sourceRec, vectorNull, WHITE);
    DrawRectangleRec(player.entity.hitBox, BLUE);
    DrawRectangleRec(boss.entity.hitBox, RED);
}

void CloseGame()
{
    UnloadTextureRec(backgroundTexture);
    UnloadImageColors(backgroundColors.colors);
    UnloadImage(backgroundColors.image);
}