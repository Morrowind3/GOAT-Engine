#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"

using namespace Engine;

void ScriptSystem::OnLaunchEngine() {
    // Empty
}

void ScriptSystem::OnLoadScene(std::shared_ptr<Scene> scene) {
    _scene = scene;
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior->OnStart();
        }
    }
}

void ScriptSystem::OnFrameTick(double deltaTime) {
    auto& input = Input::getInstance();
    input.Update();
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior->active) behavior->OnUpdate(deltaTime);
        }
        for (auto& button : gameObject->buttons) {
            // Detect if mouse clicked on button
            if(button.second.active && input.GetMouseDown(Input::MouseButton::LEFT) && button.second.dimensions.intersects(input.MousePosition())) {
                button.second.onClick->OnExternalEvent();
            }
        }
    }
}

void ScriptSystem::OnCloseEngine() {
    // Empty
}


