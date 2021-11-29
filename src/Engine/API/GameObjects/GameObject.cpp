#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(Transform transform, bool active): transform{transform}, active {active} {
}

bool GameObject::hasTag(const std::string& tag) const {
    auto tagIterator = tags.find(tag);
    return tagIterator != tags.end() && tagIterator->second;
}
