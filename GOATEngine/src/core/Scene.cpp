//
// Created by Stijn van Loon on 12-11-2021.
//

#include "Scene.hpp"

using namespace spic;

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