//
// Created by Morrowind3 on 23/11/2021.
//

#include "Camera.hpp"

Engine::Transform Camera::AdjustForCamera(const Engine::Transform& transform) {
    Engine::Transform adjusted {transform};
    Reposition(adjusted);
    Zoom(adjusted);
    return adjusted;
}

void Camera::MoveCamera(double x, double y) {
    camera.topLeft.x += x;
    camera.topLeft.y += y;
}
void Camera::setZoomLevel(float zoom) {
    zoomLevel = zoom;
}

void Camera::Reposition(Engine::Transform& t) const {
    t.position.x -= camera.topLeft.x;
    t.position.y -= camera.topLeft.y;
}

void Camera::Zoom(Engine::Transform& t) const {
t.scaleHeight *= zoomLevel;
t.scaleWidth *= zoomLevel;
}


