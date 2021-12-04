#include "Camera.hpp"
#include "../../Game/Layers.hpp" // TODO: Programmatically determine this, now we're referencing the game
#include <iostream>

using namespace Engine;

Camera::Camera(Rectangle& sceneViewPort, Point& sceneDimensions, float zoomLevel):
        _sceneViewPort{sceneViewPort}, _sceneDimensions{sceneDimensions}, _zoomLevel{zoomLevel} {
}

Transform Camera::adjustForCamera(const Transform& transform) {
    if(_trackedObject != nullptr) trackObject();
    if(transform.layer == LAYER::UI || transform.layer == LAYER::FPS) return transform;
    Engine::Transform adjusted {transform};
    reposition(adjusted);
    zoom(adjusted);
    return adjusted;
}

void Camera::moveCamera(double x, double y) {
    _sceneViewPort.topLeft.x += x;
    _sceneViewPort.topLeft.y += y;
}
void Camera::setZoomLevel(float zoom) {
    _zoomLevel = zoom;
}

/// Adjust render position (NOT LOGICAL POSITION) of object based on the viewport
void Camera::reposition(Transform& t) const {
    //TODO: Reprogram this into layer group
    //the lower from 100, the lower the speed (higher diff)
    //layer 100 = 1
    //layer 0 = 100
//    if(t.layer <= 100) {
//        double diff{101 - static_cast<double>(t.layer)};
//
//
//        double diff{static_cast<double>(t.layer) / 100};
//        diff *= 10;
//        diff = 100 - diff;
//
//        t.position.x -= (_sceneViewPort.topLeft.x / diff);
//        t.position.y -= (_sceneViewPort.topLeft.y / diff);
//    } else {
//        t.position.x -= _sceneViewPort.topLeft.x;
//        t.position.y -= _sceneViewPort.topLeft.y;
//    }

    t.position.x -= _sceneViewPort.topLeft.x;
    t.position.y -= _sceneViewPort.topLeft.y;
}

void Camera::zoom(Engine::Transform& t) const {
    //TODO: Text gets broken when zooming out. Zooming in works fine.
    t.scaleHeight *= _zoomLevel;
    t.scaleWidth *= _zoomLevel;
}

void Camera::addWaypoint(Point waypoint, int seconds) {
    if(_waypoints.empty()){
        addWaypoint(waypoint, seconds, _zoomLevel);
    } else {
        addWaypoint(waypoint, seconds, _waypoints.front().zoomTarget);
    }
}

void Camera::addWaypoint(Point waypoint, int seconds, float zoomLevel) {
    //TODO: Better time calculation. I just figured this out on my own but it's close enough in present conditions.
    int time = seconds * 60;

    //Interpolation
    double xDistance, yDistance, xPerMs, yPerMs;
    xDistance = yDistance = xPerMs = yPerMs = 0;

    if(_waypoints.empty()){
        xDistance = waypoint.x - _sceneViewPort.topLeft.x;
        yDistance = waypoint.y - _sceneViewPort.topLeft.y;
    } else {
        xDistance = waypoint.x - _waypoints.back().destination.x;
        yDistance = waypoint.y - _waypoints.back().destination.y;
    };

    if(xDistance != 0){
        xPerMs = xDistance / time;
    } if(yDistance != 0){
        yPerMs = yDistance / time;
    }

    float zoomPerMs;
    if(_waypoints.empty()){
        zoomPerMs = (zoomLevel * 100 - zoomLevel * 100) / time / 100;
    } else {
        zoomPerMs = (zoomLevel * 100 - _waypoints.back().zoomTarget * 100) / time / 100;
    };

//    _waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, zoomLevel, [&]{  }});
    _waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, zoomLevel});
}

void Camera::interpolateToNextWaypoint() {
    if(_waypoints.empty()) return;
    WaypointParams& next = _waypoints.front();
    _sceneViewPort.topLeft.x += next.xPerMs;
    _sceneViewPort.topLeft.y += next.yPerMs;
    _zoomLevel += next.zoomPerMs;
    if(std::abs(_sceneViewPort.topLeft.x) >= std::abs(next.destination.x) && std::abs(_sceneViewPort.topLeft.y) >= std::abs(next.destination.y)) _waypoints.pop();
}

void Camera::trackObject() {
    //TODO: More reliable way to get screen centre.
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto displayWidth = DM.w;
    auto displayHeight = DM.h;

    _sceneViewPort.topLeft.x = _trackedObject->transform.position.x - _sceneViewPort.width/2;
    _sceneViewPort.topLeft.y = _trackedObject->transform.position.y - _sceneViewPort.height/2;
}

void Camera::trackObject(std::shared_ptr<GameObject> object) {
    _trackedObject = std::move(object);
}
