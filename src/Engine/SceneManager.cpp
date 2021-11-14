#include "SceneManager.hpp"

using namespace Engine;

void SceneManager::AddScene(Scene& scene) {
    _scenes->insert(std::pair<std::string, std::unique_ptr<Scene>>(scene._name, std::make_unique<Scene>(scene)));

    if(_currentScene == nullptr) {
        _currentScene = GetScene(scene._name);
    }
}

Scene* SceneManager::CurrentScene() const {
    return _currentScene;
}

void SceneManager::ChangeCurrentScene(std::string& name) {
    _currentScene = GetScene(name);
}

Scene* SceneManager::GetScene(std::string& name) const {
    return _scenes->at(name).get();
}