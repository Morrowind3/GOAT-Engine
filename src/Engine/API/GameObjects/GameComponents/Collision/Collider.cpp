//
// Created by MDstu on 22/11/2021.
//

#include "Collider.hpp"

using namespace Engine;

Collider::Collider(bool active, ColliderType type) : GameComponent(active), type(type) {}

Collider::Collider() : GameComponent(active){}

Collider::~Collider() {}

std::vector<double> Collider::GetData() {
    return _data;
}
