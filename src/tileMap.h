#ifndef TILEMAP_H
#define TILEMAP_H

#include <raylib.h>

typedef struct {
    Rectangle hitBox;
    int type;
    int id;
} Tile;

typedef struct {
    Tile *tiles;
    int width;
    int height;
    int tileSize;
} TileMap;

Tile createTile(int x, int y, int size, int type, int id);
TileMap createTileMap(int width, int height, int tileSize);
Tile getTile(TileMap tileMap, int x, int y);
void setTile(TileMap tileMap, int x, int y, Tile tile);
void drawTileMap(TileMap tileMap);


#endif
