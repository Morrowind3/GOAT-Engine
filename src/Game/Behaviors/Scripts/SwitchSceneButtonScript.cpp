#include "SwitchSceneButtonScript.hpp"

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, SceneManager& sceneManager, bool active): Script(active),
    _levelName{std::move(levelName)}, _sceneManager{sceneManager} {
}

void SwitchSceneButtonScript::OnExternalEvent() {
    _sceneManager.ChangeCurrentScene(_levelName);
}
