#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, float rotation, float scaleX, float scaleY):
    _position{position}, _rotation{rotation}, _scaleX{scaleX}, _scaleY{scaleY} {
}

const Point& Transform::position() const {
    return _position;
}

float Transform::rotation() const {
    return _rotation;
}

float Transform::scaleX() const {
    return _scaleX;
}

float Transform::scaleY() const {
    return _scaleY;
}

void Transform::position(Point position) {
    _position = position;
}

void Transform::rotation(float rotation) {
    _rotation = rotation;
}

void Transform::scaleX(float scaleX) {
    _scaleX = scaleX;
}

void Transform::scaleY(float scaleY) {
    _scaleY = scaleY;
}