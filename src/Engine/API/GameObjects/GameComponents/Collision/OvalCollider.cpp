//
// Created by MDstu on 07/12/2021.
//

#include "OvalCollider.hpp"

using namespace Engine;

OvalCollider::OvalCollider(double radius, double offSetX, double offSetY, double friction, bool active) : Collider(active, friction, ColliderType::OVAL_COLLIDER) {
    _data.emplace_back(radius);
    _data.emplace_back(offSetX);
    _data.emplace_back(offSetY);
    _data.emplace_back(friction);
}