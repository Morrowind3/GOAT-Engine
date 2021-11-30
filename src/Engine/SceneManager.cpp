#include "SceneManager.hpp"

using namespace Engine;

std::shared_ptr<Scene> SceneManager::currentScene() const {
    return _currentScene;
}
