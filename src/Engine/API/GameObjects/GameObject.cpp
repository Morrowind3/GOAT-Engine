#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(Transform transform, Sprite sprite, const std::vector<GameComponent>& gameComponents)
        : transform {transform}, sprite {std::move(sprite )}, _gameComponents(gameComponents) {
}
