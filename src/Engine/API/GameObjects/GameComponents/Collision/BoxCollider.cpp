#include "BoxCollider.hpp"

using namespace Engine;

BoxCollider::BoxCollider(double width, double height, double friction, double bounciness, double offSetX, double offSetY,bool active) : Collider(active, friction, bounciness, offSetX, offSetY,ColliderType::BOX_COLLIDER) {
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}

BoxCollider::BoxCollider(bool dummy, double width, double height, double friction, double bounciness, double offSetX, double offSetY, bool active) : Collider(active, friction, bounciness, offSetX, offSetY, ColliderType::BOX_SENSOR){
    _data.emplace_back(width);
    _data.emplace_back(height);
    _data.emplace_back(friction);
    _data.emplace_back(bounciness);
}

