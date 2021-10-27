#pragma once

#include <entt/entt.hpp>
#include "Player.h"
#include "Sprite.h"
#include "TransformComponent.h"

namespace Systems {
    using namespace Components;

    class PlayerSystem {
        public:
            void update(entt::registry& registry, float deltaTime);
    };
}