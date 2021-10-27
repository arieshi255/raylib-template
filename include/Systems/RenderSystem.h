#pragma once

#include <entt/entt.hpp>
#include "TransformComponent.h"
#include "Sprite.h"

namespace Systems {
    using namespace Components;

    class RenderSystem {
        public:
            void update(entt::registry& registry, float deltaTime);

            void draw(entt::registry& registry);
    };
}