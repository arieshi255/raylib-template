#pragma once

#include <entt/entt.hpp>
#include <raylib.h>
#include <vector>
#include "Sprite.h"
#include "Player.h"
#include "TransformComponent.h"
#include "InputComponent.h"

using namespace Components;

class EntityFactory {
    private:
        entt::registry& registry;
    public:
        entt::entity create_player(Vector2 position);

        EntityFactory(entt::registry& registry);
};