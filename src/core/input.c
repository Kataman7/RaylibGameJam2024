//Gestion des entrées utilisateur (clavier, souris, etc.)
#include "init.h"

void inputUpdate()
{
    if (IsKeyDown(KEY_SPACE))
    {
        player.velY = 10;
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
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), camera);
        setTile(tileMap, (int) (pos.x / tileMap.tileSize), (int) (pos.y / tileMap.tileSize), TILE_VOID);
    }
}