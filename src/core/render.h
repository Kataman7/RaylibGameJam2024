#ifndef RENDER_H
#define RENDER_H

#include "init.h"

typedef struct {
    Texture2D texture;
    Rectangle sourceRec;
} TextureRec;

typedef struct {
    Image image;
    Color* colors;
} ImageColors;

TextureRec CreateTextureRec(char* imagePath);
ImageColors CreateImageColors(char* imagePath);
void UnloadTextureRec(TextureRec textureRec);
void DrawEntity(Texture2D texture, Rectangle sourceRec);

#endif