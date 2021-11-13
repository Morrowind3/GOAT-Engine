#include "Scene.hpp"

using namespace Engine;

size_t Scene::getId() {
    return this->sceneId;
}

void Scene::addGameObject(GameObject gameObject) {
    this->registry.insert(std::pair<size_t, GameObject>{this->idCounter, gameObject});
    ++idCounter;
}

GameObject Scene::getGameObject(size_t id) {
    return this->registry.at(id);
}