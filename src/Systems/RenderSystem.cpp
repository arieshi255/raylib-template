#include <raylib.h>
#include "RenderSystem.h"

namespace Systems {
    void RenderSystem::update(entt::registry& registry, float deltaTime) {
        auto view = registry.view<TransformComponent>();

        for (auto& entity : view) {
            auto& transform = registry.get<TransformComponent>(entity);
        }
    }

    void RenderSystem::draw(entt::registry& registry) {
        registry.view<Sprite, TransformComponent>().each([&](auto& sprite, auto& transform) {
            float ox = (sprite.frame % sprite.frames_wide) * sprite.frame_size.x;
            float oy = (int)(sprite.frame / sprite.frames_wide) * sprite.frame_size.y;

            DrawTexturePro(sprite.texture, Rectangle{ox, oy, sprite.frame_size.x, sprite.frame_size.y}, 
                            Rectangle{transform.Position.x, transform.Position.y, sprite.frame_size.x * sprite.scale, sprite.frame_size.y * sprite.scale}, 
                            Vector2{sprite.origin.x * sprite.scale, sprite.origin.y * sprite.scale}, transform.Rotation, WHITE);
        });
    }
}