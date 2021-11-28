#include "Scene.hpp"

using namespace Engine;

Scene::Scene(std::string name) : name(std::move(name)), gameObjects{} {
}

std::shared_ptr<Camera> Scene::getCamera() const {
    return std::make_shared<Camera>(_camera);
}

void Scene::moveCamera(double x, double y) {
    _camera.moveCamera(x, y);
}

void Scene::moveCameraToNextWaypoint() {
    _camera.interpolateToNextWaypoint();
}
