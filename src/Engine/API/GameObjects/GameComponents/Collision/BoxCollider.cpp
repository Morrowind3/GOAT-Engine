#include "BoxCollider.hpp"

using namespace Engine;

BoxCollider::BoxCollider(double width, double height, double friction, bool active) : Collider(active, friction, ColliderType::BOX_COLLIDER) {
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
}

BoxCollider::BoxCollider(bool dummy, double width, double height, double friction, bool active) : Collider(active, friction, ColliderType::BOX_SENSOR){
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
}

