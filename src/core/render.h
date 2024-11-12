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

typedef struct {
    TextureRec textureRec;
    Texture2D* textures;
    int frames;
    int currentFrame;
    int frameSpeed;
} TextureRecAnimated;

TextureRec CreateTextureRec(char* imagePath);
TextureRecAnimated CreateTextureRecAnimated(char* imagePath, int frameCount, int frameSpeed);
ImageColors CreateImageColors(char* imagePath);
void UnloadTextureRec(TextureRec textureRec);
void DrawEntity(TextureRec texture, Rectangle sourceRec);
void UpdateTextureRecAnimated(TextureRecAnimated* textureRecAnimated, int frames);

#endif