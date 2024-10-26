//Logique du jeu (mises à jour, interactions, etc.)
#include "init.h"

void UpdateGame()
{
    camera.target = (Vector2){player.hitBox.x, player.hitBox.y};
    UpdatePlayer();
    UpdateInput();
}

void DrawGame()
{
    DrawTextureRec(backgroundTexture.texture, backgroundTexture.sourceRec, vectorNull, WHITE);
    DrawRectangleRec(player.hitBox, BLUE);
}

void CloseGame()
{
    UnloadTextureRec(backgroundTexture);
    UnloadImageColors(backgroundColors.colors);
    UnloadImage(backgroundColors.image);
}