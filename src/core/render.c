#include "init.h"

void DrawEntity(TextureRec textureRec, Rectangle entityHitbox)
{
    DrawTexturePro(textureRec.texture, textureRec.sourceRec, entityHitbox, vectorNull, 0, WHITE);
}

TextureRec CreateTextureRec(char* imagePath)
{
    TextureRec textureRec;
    textureRec.texture = LoadTexture(imagePath);
    textureRec.sourceRec = (Rectangle){0, 0, textureRec.texture.width, textureRec.texture.height};
    return textureRec;
}

TextureRecAnimated CreateTextureRecAnimated(char* imagePath, int frames, int frameSpeed)
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
    textureRecAnimated.frames = frames;
    textureRecAnimated.currentFrame = 0;
    textureRecAnimated.frameSpeed = frameSpeed;
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

void UpdateTextureRecAnimated(TextureRecAnimated* textureRecAnimated, int frames)
{
    textureRecAnimated->frames++;
    if (textureRecAnimated->frames >= textureRecAnimated->frameSpeed)
    {
        textureRecAnimated->frames = 0;
        textureRecAnimated->currentFrame++;
        if (textureRecAnimated->currentFrame >= frames)
        {
            textureRecAnimated->currentFrame = 0;
        }
        textureRecAnimated->textureRec = (TextureRec){textureRecAnimated->textures[textureRecAnimated->currentFrame], (Rectangle){0, 0, textureRecAnimated->textures[textureRecAnimated->currentFrame].width, textureRecAnimated->textures[textureRecAnimated->currentFrame].height}};
    }
}