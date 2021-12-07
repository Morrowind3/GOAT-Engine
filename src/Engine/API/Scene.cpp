#include "Scene.hpp"

using namespace Engine;

// Underscore suffixes because else it would save the memory address of whichever code constructed this scene
// TODO: But this will be fixed as soon as these members are encapsulated
Scene::Scene(std::string name, Point dimensions_, Rectangle viewPort_): name(std::move(name)),
    dimensions{dimensions_}, viewPort{viewPort_}, _camera{viewPort,dimensions,layerGroups,1} {
    layerGroups.insert(std::make_pair(0,LayerGroup{})); // Reserved "default" group without special UI or parallax settings
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


