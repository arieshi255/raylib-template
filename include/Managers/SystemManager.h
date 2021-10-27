#pragma once

#include <entt/entt.hpp>
#include "RenderSystem.h"
#include "InputSystem.h"
#include "PlayerSystem.h"
#include "EntityFactory.h"

using namespace Systems;

class SystemManager {
public:
	void activate();
	void update();

	SystemManager();
private:
	entt::registry registry;

	// Systems
	PlayerSystem playerSystem;
	RenderSystem renderSystem;
	InputSystem inputSystem;

    int screenWidth = 800;
    int screenHeight = 450;
    float delta = 0.0f;
};