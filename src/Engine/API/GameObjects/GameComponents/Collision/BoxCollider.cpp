#include "BoxCollider.hpp"

using namespace Engine;

BoxCollider::BoxCollider(double width, double height, double friction, double bounciness, bool active) : Collider(active, friction, bounciness, ColliderType::BOX_COLLIDER) {
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}

BoxCollider::BoxCollider(bool dummy, double width, double height, double friction, double bounciness, bool active) : Collider(active, friction, bounciness, ColliderType::BOX_SENSOR){
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}

