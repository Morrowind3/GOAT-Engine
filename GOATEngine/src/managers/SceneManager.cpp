//
// Created by Stijn van Loon on 12-11-2021.
//

#include "SceneManager.hpp"

using namespace spic;

Scene* SceneManager::getActiveScene() {
    return this->activeScene;
}

bool SceneManager::hasActiveScene() {
    return this->activeScene != nullptr;
}

void SceneManager::addScene(Scene* scene) {
    this->registry.insert(std::pair<size_t, Scene*>{this->idCounter, scene});
    ++idCounter;
}

void SceneManager::setActiveScene(size_t id) {
    this->activeScene = this->registry.at(id);
}

void SceneManager::loadScene(size_t id) {
    //TODO
}

void SceneManager::unloadScene(size_t id) {
    //TODO
}

void SceneManager::destoryScene(size_t id) {
    //TODO
}