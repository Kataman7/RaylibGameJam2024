#ifndef TILEMAP_H
#define TILEMAP_H

#include "../core/init.h"

typedef struct {
    Rectangle hitBox;
    int type;
    int id;
} Tile;

typedef struct {
    Tile *tiles;
    TextureRec textureRec;
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


Tile createTile(int x, int y, int size, int type, int id);
TileMap createTileMap(int width, int height, int tileSize);
Tile getTile(TileMap tileMap, int x, int y);
void setTile(TileMap tileMap, int x, int y, TileID tile);
void drawTileMap(TileMap tileMap);


#endif
