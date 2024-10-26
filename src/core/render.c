#include "init.h"

void DrawEntity(Texture2D texture, Rectangle sourceRec)
{
    DrawTextureRec(texture, sourceRec, vectorNull, WHITE);
}

TextureRec CreateTextureRec(char* imagePath)
{
    TextureRec textureRec;
    textureRec.texture = LoadTexture(imagePath);
    textureRec.sourceRec = (Rectangle){0, 0, textureRec.texture.width, textureRec.texture.height};
    return textureRec;
}

ImageColors CreateImageColors(char* imagePath)
{
    ImageColors imageColor;
    imageColor.image = LoadImage(imagePath);
    imageColor.colors = LoadImageColors(imageColor.image);
    return imageColor;
}

void UnloadTextureRec(TextureRec textureRec)
{
    UnloadTexture(textureRec.texture);
}