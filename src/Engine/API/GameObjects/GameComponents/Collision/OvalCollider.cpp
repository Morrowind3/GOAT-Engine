#include "OvalCollider.hpp"

using namespace Engine;

OvalCollider::OvalCollider(double radius, double offSetX, double offSetY, double friction, double bounciness, bool active):
Collider(active, friction, bounciness, offSetX, offSetY, ColliderType::OVAL_COLLIDER) {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}