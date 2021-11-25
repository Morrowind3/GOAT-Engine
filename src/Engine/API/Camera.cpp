#include "Camera.hpp"

Engine::Transform Camera::AdjustForCamera(const Engine::Transform& transform) {
    if(transform.layer == Engine::LAYER::UI) return transform;
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
    if(t.layer == Engine::LAYER::PARALLAX_BACKGROUND){
        t.position.x -= (camera.topLeft.x / 3);
        t.position.y -= (camera.topLeft.y / 3);
    } else {
        t.position.x -= camera.topLeft.x;
        t.position.y -= camera.topLeft.y;
    }
}

void Camera::Zoom(Engine::Transform& t) const {
    //TODO: Text gets broken when zooming out. Zooming in works fine.
    t.scaleHeight *= zoomLevel;
    t.scaleWidth *= zoomLevel;
}