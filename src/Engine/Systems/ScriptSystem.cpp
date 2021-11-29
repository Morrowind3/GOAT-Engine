#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"
#include "../Utilities/Globals.hpp"

using namespace Engine;

void ScriptSystem::onLaunchEngine() {
    _debug.log("Script system launch"); // Empty
}

void ScriptSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Script system load");
    Globals::getInstance().sceneReset();
    _scene = scene;
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior.second->active) behavior.second->onStart();
        }
    }
}

void ScriptSystem::onFrameTick(const double deltaTime) {
    auto& input = Input::getInstance();
    input.update();
    _physics.runCollisionScripts();
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior.second->active) behavior.second->onUpdate(deltaTime);
        }
        for (auto& button : gameObject->buttons) {
            // Detect if mouse clicked on button
            if(button.second.active && input.getMouseDown(MouseButton::LEFT) && button.second.dimensions.intersects(
                    input.mousePosition())) {
                button.second.onClick->onExternalEvent();
            }
        }
    }
}

void ScriptSystem::onCloseEngine() {
    _debug.log("Script system close"); // Empty
}


