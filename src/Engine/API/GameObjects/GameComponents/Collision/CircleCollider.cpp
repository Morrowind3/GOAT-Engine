//
// Created by MDstu on 26/11/2021.
//

#include "CircleCollider.hpp"

using namespace Engine;

CircleCollider::CircleCollider(double radius, bool active) : Collider{active, ColliderType::CIRCLE_COLLIDER}, radius{radius}{
    _data.emplace_back(radius);
}
