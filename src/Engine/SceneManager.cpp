#include "SceneManager.hpp"

using namespace Engine;

std::shared_ptr<Scene> SceneManager::CurrentScene() const {
    return _currentScene;
}
