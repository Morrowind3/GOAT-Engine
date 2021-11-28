#include "SwitchSceneButtonScript.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

SwitchSceneButtonScript::SwitchSceneButtonScript(std::string levelName, SceneManager& sceneManager, bool active): Script(active),
    _levelName{std::move(levelName)}, _sceneManager{sceneManager} {
}

void SwitchSceneButtonScript::onExternalEvent() {
    Debug::getInstance().log("Switch scene called towards " + _levelName);
    _sceneManager.changeCurrentScene(_levelName);
}
