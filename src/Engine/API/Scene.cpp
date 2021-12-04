#include "Scene.hpp"

using namespace Engine;

// Underscore suffixes because else it would save the memory address of whichever code constructed this scene
// And then it would read out garbage code and draw sprites at positions such as -1.7E^55
Scene::Scene(std::string name, Point dimensions_, Rectangle viewPort_): name(std::move(name)),
    dimensions{dimensions_}, viewPort{viewPort_}, _camera{viewPort,dimensions,1} {
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


