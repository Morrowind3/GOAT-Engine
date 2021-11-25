#include "Camera.hpp"
#include <iostream>

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
void Camera::SetZoomLevel(float zoom) {
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

void Camera::AddWaypoint(Point waypoint, int seconds) {
    if(waypoints.empty()){
        AddWaypoint(waypoint, seconds, zoomLevel);
    } else {
        AddWaypoint(waypoint, seconds, waypoints.front().zoomTarget);
    }
}

void Camera::AddWaypoint(Point waypoint, int seconds, float _zoomLevel) {
    //TODO: Better time calculation. I just pulled this out of my ass but it's close enough in present conditions.
    int time = seconds * 60;

    //Interpolation
    double xDistance, yDistance, xPerMs, yPerMs;
    xDistance = yDistance = xPerMs = yPerMs = 0;

    if(waypoints.empty()){
        xDistance =  waypoint.x - camera.topLeft.x;
        yDistance =  waypoint.y - camera.topLeft.y;
    } else {
        xDistance = waypoint.x - waypoints.back().destination.x;
        yDistance = waypoint.y - waypoints.back().destination.y;
    };

    if(xDistance != 0){
        xPerMs = xDistance / time;
    } if(yDistance != 0){
        yPerMs = yDistance / time;
    }

    float zoomPerMs;
    if(waypoints.empty()){
        zoomPerMs = (_zoomLevel*100 - zoomLevel*100) / time / 100;
    } else {
        zoomPerMs = (_zoomLevel*100 - waypoints.back().zoomTarget*100) / time / 100;
    };

//    waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, _zoomLevel, [&]{  }});
    waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, _zoomLevel});
}

void Camera::InterpolateToNextWaypoint() {
    if(waypoints.empty()) return;
    WaypointParams& next = waypoints.front();
    camera.topLeft.x += next.xPerMs;
    camera.topLeft.y += next.yPerMs;
    zoomLevel += next.zoomPerMs;
    if(std::abs(camera.topLeft.x) >= std::abs(next.destination.x) && std::abs(camera.topLeft.y) >= std::abs(next.destination.y)) waypoints.pop();
}

