//
// Created by Morrowind3 on 23/11/2021.
//

#include "Camera.hpp"

Engine::Transform Camera::AdjustForCamera(const Engine::Transform& transform) {
    Engine::Transform adjusted {transform};
    Reposition(adjusted);

    return adjusted;
}

void Camera::Reposition(Engine::Transform& t) const {
    t.position.x -= camera.topLeft.x;
    t.position.y -= camera.topLeft.y;
}

void Camera::Crop(Engine::Transform& t) const {

}

void Camera::MoveCamera(double x, double y) {
    camera.topLeft.x += x;
    camera.topLeft.y += y;
}

