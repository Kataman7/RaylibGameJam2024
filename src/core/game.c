//Logique du jeu (mises à jour, interactions, etc.)
#include "init.h"

void UpdateGame()
{
    camera.target = (Vector2){player.entity.hitBox.x, player.entity.hitBox.y};
    UpdatePlayer();
    UpdateInput();
    UpdateBoss();

    frameCount++;
}

void DrawGame()
{
    DrawTextureRec(backgroundTexture.texture, backgroundTexture.sourceRec, vectorNull, WHITE);

    DrawEntity(texturePlayerIdle.textureRec, player.entity.hitBox);
   // DrawRectangleRec(player.entity.hitBox, BLUE);

    DrawRectangleRec(boss.entity.hitBox, RED);
}

void CloseGame()
{
    UnloadTextureRec(backgroundTexture);
    UnloadImageColors(backgroundColors.colors);
    UnloadImage(backgroundColors.image);
}