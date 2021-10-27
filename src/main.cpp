#include <raylib.h>
#include "SystemManager.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

SystemManager system_man;

void main_loop() {
    // Main game loop
    system_man.update();
}

int main() {
    // Run game
    system_man.activate();

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(main_loop, 60, 1);
    #endif

    // De-initialization
    CloseWindow();

    return 0;
}
