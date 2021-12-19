#include "CircleCollider.hpp"

using namespace Engine;

CircleCollider::CircleCollider(double radius, bool active, double offSetX, double offSetY, double friction, double bounciness) : Collider{active, friction, bounciness, offSetX, offSetY, ColliderType::CIRCLE_COLLIDER} {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}
CircleCollider::CircleCollider(bool dummy, double radius, bool active,double offSetX, double offSetY, double friction, double bounciness) : Collider{active,  friction, bounciness, offSetX, offSetY, ColliderType::CIRCLE_SENSOR} {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}

