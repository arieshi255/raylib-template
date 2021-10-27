#pragma once

#include <raylib.h>

namespace Components {
    struct Sprite {
        public:
            Texture2D texture;
            Vector2 frame_size;
            int max_frame;
            int frames_wide;
            Vector2 origin;
            int frame;
            int scale;
    };
}