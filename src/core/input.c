//Gestion des entrées utilisateur (clavier, souris, etc.)
#include "init.h"

void UpdateInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        if (player.jumpCount < player.jumpMax)
        {
            player.velY = -10;
            player.jumpCount++;
        }
    }
    if (IsKeyDown(KEY_A))
    {
        player.velX -= 0.5;
    }
    if (IsKeyDown(KEY_D))
    {
        player.velX += 0.5;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        printf("Mouse left button pressed\n");
        /*
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), camera);
        SetTile(tileMap, (int) (pos.x / tileMap.tileSize), (int) (pos.y / tileMap.tileSize), TILE_VOID);
        */
    }
}