#include "EntityFactory.h"

EntityFactory::EntityFactory(entt::registry& registry) : registry(registry) { }

entt::entity EntityFactory::create_player(Vector2 position) {
    auto entity = registry.create();

    registry.emplace<Sprite>(entity, Sprite{LoadTexture("resources/sprites/link/link_sheet.png"), Vector2{32, 32}, 4, 4, 
                                                Vector2{0, 0}, 0, 4});
    registry.emplace<TransformComponent>(entity, TransformComponent{position, Vector2{0, 0}, Vector2{32, 32}, 0.0f});
    registry.emplace<InputComponent>(entity, InputComponent{std::vector<KeyboardKey>{KEY_RIGHT, KEY_LEFT}});
    registry.emplace<Player>(entity, Player());

    return entity;
}