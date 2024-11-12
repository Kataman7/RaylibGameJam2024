//Gestion des entrées utilisateur (clavier, souris, etc.)
#include "init.h"

void UpdateInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        if (player.jumpCount < 2)
        {
            player.velY = -player.jumpForce;
            player.jumpCount++;
        }
    }
    if (IsKeyDown(KEY_A))
    {
        player.velX -= player.speed;
    }
    if (IsKeyDown(KEY_D))
    {
        player.velX += player.speed;
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