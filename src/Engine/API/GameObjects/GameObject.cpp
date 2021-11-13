#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(Transform transform, Sprite sprite, bool active): transform {transform}, sprite{std::move(sprite)}, active {active},
    scripts { std::make_unique<std::vector<Script*>>() } {
}
