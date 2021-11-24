#include "Scene.hpp"

using namespace Engine;

Scene::Scene(std::string name) : name(std::move(name)), gameObjects{}, _camera({0,0,1.0}) {
}

void Scene::SetCamera(Camera camera) {
_camera = camera;
}

std::shared_ptr<Camera> Scene::GetCamera() const {
    return std::make_shared<Camera>(_camera);
}

void Scene::MoveCamera(double x, double y) {
    _camera.MoveCamera(x, y);
}
