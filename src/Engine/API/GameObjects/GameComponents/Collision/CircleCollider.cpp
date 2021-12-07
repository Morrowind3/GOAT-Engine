#include "CircleCollider.hpp"

using namespace Engine;

CircleCollider::CircleCollider(double radius, bool active, double offSetX, double offSetY) : Collider{active, ColliderType::CIRCLE_COLLIDER} {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
}
CircleCollider::CircleCollider(bool dummy, double radius, bool active,double offSetX, double offSetY) : Collider{active, ColliderType::CIRCLE_SENSOR} {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
}

