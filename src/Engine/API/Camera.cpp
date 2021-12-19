#include "Camera.hpp"
#include "../Utilities/Clock.hpp"

using namespace Engine;

Camera::Camera(Rectangle& sceneViewPort, std::map<unsigned int,LayerGroup>& layerGroups, float zoomLevel):
    _sceneViewPort{sceneViewPort}, _layerGroups{layerGroups}, _zoomLevel{zoomLevel} {
}

Transform Camera::adjustForCamera(const Transform& logicalPosition) {
    if(_trackedObject != nullptr) trackObject();
    Transform renderPosition {logicalPosition};
    reposition(renderPosition);
    zoom(renderPosition);
    return renderPosition;
}

[[maybe_unused]] void Camera::moveCamera(double x, double y) {
    _sceneViewPort.topLeft.x += x;
    _sceneViewPort.topLeft.y += y;
}

[[maybe_unused]] void Camera::setZoomLevel(float zoom) {
    _zoomLevel = zoom;
}

/// Adjust render position (NOT LOGICAL POSITION) of object based on the viewport
void Camera::reposition(Transform& transform) const {
    // Find layer group associated with transform
    auto layerGroupIterator = _layerGroups.find(transform.layerGroup);
    if (layerGroupIterator == _layerGroups.end()) { // Layer group not found, so defaulting to the default layer group
        layerGroupIterator = _layerGroups.find(0);
    }
    LayerGroup& layerGroup = layerGroupIterator->second;

    // Communicate what the layer group state is of the transform
    transform._isGui = layerGroup.ui;
    transform._isParallax = abs(layerGroup.parallax-1.0) > 0.00000001;

    // UI layer group needs no repositioning
    if (layerGroup.ui) return;

    // Adjust for parallax scrolling amount and position of the object relative to the viewport
    transform.position.x -= _sceneViewPort.topLeft.x * layerGroup.parallax;
    transform.position.y -= _sceneViewPort.topLeft.y * layerGroup.parallax;
}

void Camera::zoom(Engine::Transform& t) const {
    t.scaleHeight *= _zoomLevel;
    t.scaleWidth *= _zoomLevel;
}

[[maybe_unused]] void Camera::addWaypoint(Point waypoint, int seconds) {
    if(_waypoints.empty()) {
        addWaypoint(waypoint, seconds, _zoomLevel);
    } else {
        addWaypoint(waypoint, seconds, _waypoints.front().zoomTarget);
    }
}

[[maybe_unused]] void Camera::addWaypoint(Point waypoint, int seconds, float zoomLevel) {
    double time = seconds * Clock::getInstance().getMaxFps();

    // Interpolation
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
    }

    _waypoints.emplace(WaypointParams{xPerMs, yPerMs, zoomPerMs, waypoint, zoomLevel});
}

[[maybe_unused]] void Camera::interpolateToNextWaypoint() {
    if(_waypoints.empty()) return;
    WaypointParams& next = _waypoints.front();
    _sceneViewPort.topLeft.x += next.xPerMs;
    _sceneViewPort.topLeft.y += next.yPerMs;
    _zoomLevel += next.zoomPerMs;
    if(std::abs(_sceneViewPort.topLeft.x) >= std::abs(next.destination.x) && std::abs(_sceneViewPort.topLeft.y) >= std::abs(next.destination.y)) _waypoints.pop();
}

void Camera::trackObject() {
    auto& transform = _trackedObject->transform;
    _sceneViewPort.topLeft.x = transform.position.x - _sceneViewPort.width/2.6;
    _sceneViewPort.topLeft.y = transform.position.y - _sceneViewPort.height/2;
}

void Camera::trackObject(std::shared_ptr<GameObject> object) {
    _trackedObject = std::move(object);
}
