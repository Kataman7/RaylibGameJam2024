#include "../core/init.h"

Tile createTile(int x, int y, int size, int type, int id)
{
    Tile tile;
    tile.hitBox = (Rectangle){x, y, size, size};
    tile.type = type;
    tile.id = id;
    return tile;
}

TileMap createTileMap(int width, int height, int tileSize)
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
            setTile(tileMap, x, y, TILE_VOID);
        }
    }

    return tileMap;
}

Tile getTile(TileMap tileMap, int x, int y)
{
    return tileMap.tiles[y * tileMap.width + x];
}

void setTile(TileMap tileMap, int x, int y, TileID tileID)
{
    tileMap.tiles[y * tileMap.width + x] = createTile(
        x * tileMap.tileSize, y * tileMap.tileSize, tileMap.tileSize,
        TILE_GROUND, tileID);
}

void drawTileMap(TileMap tileMap)
{
    for (int y = 0; y < tileMap.height; y++)
    {
        for (int x = 0; x < tileMap.width; x++)
        {
            DrawRectangleRec(getTile(tileMap, x, y).hitBox, WHITE);
        }
    }
}