#include "CircleCollider.hpp"

using namespace Engine;

CircleCollider::CircleCollider(double radius, bool active) : Collider{active, ColliderType::CIRCLE_COLLIDER} {
    _data.emplace_back(radius);
}
