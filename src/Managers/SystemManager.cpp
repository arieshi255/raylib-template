#include "SystemManager.h"

SystemManager::SystemManager() { }

void SystemManager::activate() {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    EntityFactory factory(registry);

    factory.create_player(Vector2{50, 50});

    delta = GetFrameTime();

    #if !defined(PLATFORM_WEB)
        SetTargetFPS(60);
        while (!WindowShouldClose()) {
            update();
        }
    #endif
}

void SystemManager::update() {
    //Update
    inputSystem.update(registry, delta);
    playerSystem.update(registry, delta);
    renderSystem.update(registry, delta);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);
    renderSystem.draw(registry);
    EndDrawing();

    delta = GetFrameTime();
}