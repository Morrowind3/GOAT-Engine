#include "Scene.hpp"

using namespace Engine;

Scene::Scene(std::string name) : name(std::move(name)), _camera{viewPort,dimensions,1} {
}

std::shared_ptr<Camera> Scene::getCamera() const {
    return std::make_shared<Camera>(_camera);
}

[[maybe_unused]] void Scene::moveCamera(double x, double y) {
    _camera.moveCamera(x, y);
}

void Scene::moveCameraToNextWaypoint() {
    _camera.interpolateToNextWaypoint();
}
