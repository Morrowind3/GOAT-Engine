#include "BoxCollider.hpp"

using namespace Engine;

BoxCollider::BoxCollider(double width, double height, bool active) : Collider(active, ColliderType::BOX_COLLIDER) {
    _data.emplace_back(width);
    _data.emplace_back(height);
}


BoxCollider::BoxCollider(double width, double height, bool isSensor, bool active) : Collider(active, ColliderType::BOX_SENSOR) {
    _data.emplace_back(width);
    _data.emplace_back(height);
}
