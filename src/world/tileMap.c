#include "../core/init.h"

Tile GreateTile(int x, int y, int size, int type, int id)
{
    Tile tile;
    tile.hitBox = (Rectangle){x, y, size, size};
    tile.type = type;
    tile.id = id;
    return tile;
}

TileMap CreateTileMap(int width, int height, int tileSize)
{
    TileMap tileMap;
    tileMap.tiles = (Tile *)malloc(width * height * sizeof(Tile));
    tileMap.width = width;
    tileMap.height = height;
    tileMap.tileSize = tileSize;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            SetTile(tileMap, x, y, TILE_VOID);
        }
    }

    return tileMap;
}

Tile GetTile(TileMap tileMap, int x, int y)
{
    return tileMap.tiles[y * tileMap.width + x];
}

void SetTile(TileMap tileMap, int x, int y, TileID tileID)
{
    tileMap.tiles[y * tileMap.width + x] = GreateTile(
        x * tileMap.tileSize, y * tileMap.tileSize, tileMap.tileSize,
        TILE_GROUND, tileID);
}

void DrawTileMap(TileMap tileMap)
{
    for (int y = 0; y < tileMap.height; y++)
    {
        for (int x = 0; x < tileMap.width; x++)
        {
            DrawRectangleRec(GetTile(tileMap, x, y).hitBox, WHITE);
            Tile tile = GetTile(tileMap, x, y);
            DrawEntity(tile.textureRec.texture, tile.hitBox);
        }
    }
}