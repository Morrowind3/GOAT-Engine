#include "Scene.hpp"

using namespace Engine;

// Underscore suffixes because else it would save the memory address of whichever code constructed this scene
Scene::Scene(std::string name, Point dimensions, Rectangle viewPort): _name{std::move(name)}, _dimensions{dimensions}, _viewPort{viewPort}, _camera{_viewPort, _dimensions, layerGroups, 1} {
    layerGroups.insert(std::make_pair(0,LayerGroup{})); // Reserved "default" group without special UI or parallax settings
}

std::shared_ptr<Camera> Scene::getCamera() const {
    return std::make_shared<Camera>(_camera);
}

const std::string& Scene::getName() const {
    return _name;
}

const Rectangle& Scene::getViewPort() const {
    return _viewPort;
}


