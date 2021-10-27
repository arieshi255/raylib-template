#pragma once

#include <raylib.h>

namespace Components {
    struct TransformComponent {
        public:
            Vector2 Position{};
            Vector2 Velocity{};
            Vector2 Size{};
            float Rotation{};
    };
}