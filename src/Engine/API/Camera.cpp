#include "Camera.hpp"
#include <iostream>

using namespace Engine;

Camera::Camera(Rectangle& sceneViewPort, Point& sceneDimensions, std::map<unsigned int,LayerGroup>& layerGroups, float zoomLevel):
    _sceneViewPort{sceneViewPort}, _sceneDimensions{sceneDimensions}, _layerGroups{layerGroups}, _zoomLevel{zoomLevel} {
}

Transform Camera::adjustForCamera(const Transform& logicalPosition) {
    if(_trackedObject != nullptr) trackObject();
    Transform renderPosition {logicalPosition};
    reposition(renderPosition);
    zoom(renderPosition);
    return renderPosition;
}

void Camera::moveCamera(double x, double y) {
    _sceneViewPort.topLeft.x += x;
    _sceneViewPort.topLeft.y += y;
}

void Camera::setZoomLevel(float zoom) {
    _zoomLevel = zoom;
}

/// Adjust render position (NOT LOGICAL POSITION) of object based on the viewport
void Camera::reposition(Transform& transform) const {
    // Find layer group associated with transform
    auto layerGroupRef = _layerGroups.find(transform.layerGroup);
    if (layerGroupRef == _layerGroups.end()) { // Layer group not found, so defaulting to the default layer group
        layerGroupRef = _layerGroups.find(0);
    }
    LayerGroup& layerGroup = layerGroupRef->second;

    // TODO: I hastly made this, make this better
    transform._isGui = layerGroup.ui;
    transform._isParallax = abs(layerGroup.parallax-1.0) > 0.00000001;

    // UI layer group needs no repositioning
    if (layerGroup.ui) return;

    // Adjust for parallax scrolling amount and position of the object relative to the viewport
    transform.position.x -= _sceneViewPort.topLeft.x * layerGroup.parallax;
    transform.position.y -= _sceneViewPort.topLeft.y * layerGroup.parallax;
}

void Camera::zoom(Engine::Transform& t) const {
    //TODO: Text gets broken when zooming out. Zooming in works fine.
    t.scaleHeight *= _zoomLevel;
    t.scaleWidth *= _zoomLevel;
}

void Camera::addWaypoint(Point waypoint, int seconds) {
    if(_waypoints.empty()) {
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
    // TODO: Find some way to do this properly (now it's off-center), base this off engine call values?
    auto& transform = _trackedObject->transform;
    _sceneViewPort.topLeft.x = transform.position.x - _sceneViewPort.width/3;
    _sceneViewPort.topLeft.y = transform.position.y - _sceneViewPort.height/2;
}

void Camera::trackObject(std::shared_ptr<GameObject> object) {
    _trackedObject = std::move(object);
}
