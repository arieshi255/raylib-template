#pragma once

#include <entt/entt.hpp>
#include "InputComponent.h"
#include "TransformComponent.h"
#include "Player.h"

namespace Systems {
    using namespace Components;
    
    class InputSystem {
        public:
            void update(entt::registry& registry, float deltaTime);
    };
}