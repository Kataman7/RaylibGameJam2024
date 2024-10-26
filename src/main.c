#include "raylib.h"

#if defined(PLATFORM_WEB)
    #define CUSTOM_MODAL_DIALOGS            
    #include <emscripten/emscripten.h>      
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/init.h"

#define SUPPORT_LOG_INFO
#if defined(SUPPORT_LOG_INFO)
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

static const int screenWidth = 1280;
static const int screenHeight = 720;

static RenderTexture2D target = { 0 };  
static void UpdateDrawFrame(void);

int main(void)
{
#if !defined(_DEBUG)
    SetTraceLogLevel(LOG_NONE);
#endif
    InitWindow(screenWidth, screenHeight, "raylib gamejam");
    Init();
    target = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void)
{
    UpdateGame();

    BeginTextureMode(target);
        ClearBackground(RAYWHITE);        
        BeginMode2D(camera);
            DrawGame();
        EndMode2D();
        DrawFPS(10, 10);
    EndTextureMode();

    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height }, (Rectangle){ 0, 0, (float)target.texture.width, (float)target.texture.height }, (Vector2){ 0, 0 }, 0.0f, WHITE);
    EndDrawing();
}