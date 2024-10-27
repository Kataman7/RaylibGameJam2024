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

TextureRecAnimated CreateTextureRecAnimated(char* imagePath, int frames)
{
    TextureRecAnimated textureRecAnimated;
    textureRecAnimated.textures = malloc(sizeof(Texture2D) * frames);
    for (int i = 0; i < frames; i++)
    {
        char framePath[100];
        sprintf(framePath, "%s%d.png", imagePath, i);
        textureRecAnimated.textures[i] = LoadTexture(framePath);
    }
    textureRecAnimated.textureRec = (TextureRec){textureRecAnimated.textures[0], (Rectangle){0, 0, textureRecAnimated.textures[0].width, textureRecAnimated.textures[0].height}};
    return textureRecAnimated;
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