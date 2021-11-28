#include "Camera.hpp"
#include <iostream>
#include <utility>

using namespace Engine;

Transform Camera::AdjustForCamera(const Engine::Transform& transform) {
    if(transform.layer == Engine::LAYER::UI) return transform;
    Engine::Transform adjusted {transform};
    if(_trackedObject != nullptr) TrackObject();
    Reposition(adjusted);
    Zoom(adjusted);
    return adjusted;
}

void Camera::MoveCamera(double x, double y) {
    _camera.topLeft.x += x;
    _camera.topLeft.y += y;
}
void Camera::SetZoomLevel(float zoom) {
    _zoomLevel = zoom;
}

void Camera::Reposition(Engine::Transform& t) const {
    if(t.layer == Engine::LAYER::PARALLAX_BACKGROUND){
        t.position.x -= (_camera.topLeft.x / 3);
        t.position.y -= (_camera.topLeft.y / 3);
    } else {
        t.position.x -= _camera.topLeft.x;
        t.position.y -= _camera.topLeft.y;
    }
}

void Camera::Zoom(Engine::Transform& t) const {
    //TODO: Text gets broken when zooming out. Zooming in works fine.
    t.scaleHeight *= _zoomLevel;
    t.scaleWidth *= _zoomLevel;
}

void Camera::AddWaypoint(Point waypoint, int seconds) {
    if(_waypoints.empty()){
        AddWaypoint(waypoint, seconds, _zoomLevel);
    } else {
        AddWaypoint(waypoint, seconds, _waypoints.front().zoomTarget);
    }
}

void Camera::AddWaypoint(Point waypoint, int seconds, float _zoomLevel) {
    //TODO: Better time calculation. I just pulled this out of my ass but it's close enough in present conditions.
    int time = seconds * 60;

    //Interpolation
    double xDistance, yDistance, xPerMs, yPerMs;
    xDistance = yDistance = xPerMs = yPerMs = 0;

    if(_waypoints.empty()){
        xDistance = waypoint.x - _camera.topLeft.x;
        yDistance = waypoint.y - _camera.topLeft.y;
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
        zoomPerMs = (_zoomLevel*100 - _zoomLevel * 100) / time / 100;
    } else {
        zoomPerMs = (_zoomLevel*100 - _waypoints.back().zoomTarget * 100) / time / 100;
    };

//    _waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, _zoomLevel, [&]{  }});
    _waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, _zoomLevel});
}

void Camera::InterpolateToNextWaypoint() {
    if(_waypoints.empty()) return;
    WaypointParams& next = _waypoints.front();
    _camera.topLeft.x += next.xPerMs;
    _camera.topLeft.y += next.yPerMs;
    _zoomLevel += next.zoomPerMs;
    if(std::abs(_camera.topLeft.x) >= std::abs(next.destination.x) && std::abs(_camera.topLeft.y) >= std::abs(next.destination.y)) _waypoints.pop();
}

void Camera::TrackObject()
{
    //TODO: More reliable way to get screen centre.
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto displayWidth = DM.w;
    auto displayHeight = DM.h;

    _camera.topLeft.x = _trackedObject->transform.position.x - displayWidth / 3;
    _camera.topLeft.y = _trackedObject->transform.position.y - (displayHeight / 2);
}

void Camera::TrackObject(std::shared_ptr<GameObject> object) {
    _trackedObject = std::move(object);
}

