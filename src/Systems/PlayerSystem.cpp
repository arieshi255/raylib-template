#include  "PlayerSystem.h"

namespace Systems {
    void PlayerSystem::update(entt::registry& registry, float deltaTime) {
        auto view = registry.view<Player, TransformComponent, Sprite>();
        
        for (auto& entity : view) {
            auto& player = view.get<Player>(entity);
            auto& sprite = view.get<Sprite>(entity);
            auto& transform = view.get<TransformComponent>(entity);

            transform.Position.x += (int)(transform.Velocity.x * deltaTime);
            transform.Position.y += (int)(transform.Velocity.y * deltaTime);

            transform.Velocity.x = 0;
            transform.Velocity.y = 0;
        }
    }
}