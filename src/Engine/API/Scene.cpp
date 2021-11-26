#include "Scene.hpp"

using namespace Engine;

Scene::Scene(std::string name) : name(std::move(name)), gameObjects{} {
}

std::shared_ptr<Camera> Scene::GetCamera() const {
    return std::make_shared<Camera>(_camera);
}

void Scene::MoveCamera(double x, double y) {
    _camera.MoveCamera(x, y);
}

void Scene::MoveCameraToNextWaypoint() {
    _camera.InterpolateToNextWaypoint();
}
