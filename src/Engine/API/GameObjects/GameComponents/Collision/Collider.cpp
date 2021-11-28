#include "Collider.hpp"

using namespace Engine;

Collider::Collider(bool active, ColliderType type) : GameComponent(active), type(type) {}

Collider::Collider() : GameComponent(false){}

Collider::~Collider() {}

std::vector<double> Collider::getData() const {
    return _data;
}
