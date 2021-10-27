#include <raylib.h>
#include <iostream>
#include "InputSystem.h"

namespace Systems {
	void InputSystem::update(entt::registry& registry, float deltaTime) {
		registry.view<TransformComponent, InputComponent>().each([&](auto Entity, TransformComponent& transformComponent, InputComponent& inputComponent) {		
			for (auto& currentKey : inputComponent.KeyList) {
				if (IsKeyDown(currentKey) && currentKey == KeyboardKey::KEY_RIGHT) {
					transformComponent.Velocity.x += _ACCELERATION;
				}
				else if (IsKeyDown(currentKey) && currentKey == KeyboardKey::KEY_LEFT) {
					transformComponent.Velocity.x -= _ACCELERATION;
				}
			}
		});
	}
}