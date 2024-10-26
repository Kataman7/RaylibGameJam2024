#ifndef TILEMAP_H
#define TILEMAP_H

#include "../core/init.h"

typedef struct {
    Rectangle hitBox;
    TextureRec textureRec;
    int type;
    int id;
} Tile;

typedef struct {
    Tile *tiles;
    int width;
    int height;
    int tileSize;
} TileMap;

typedef enum TileID
{
    TILE_VOID,
    TILE_GROUND,
} TileID;

typedef enum TileState
{
    TILE_EMPTY,
    TILE_SOLID,
} TileState;


Tile GreateTile(int x, int y, int size, int type, int id);
TileMap CreateTileMap(int width, int height, int tileSize);
Tile GetTile(TileMap tileMap, int x, int y);
void SetTile(TileMap tileMap, int x, int y, TileID tile);
void DrawTileMap(TileMap tileMap);


#endif
