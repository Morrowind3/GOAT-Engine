#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"
#include "../Utilities/Globals.hpp"

using namespace Engine;

void ScriptSystem::OnLaunchEngine() {
    // Empty
}

void ScriptSystem::OnLoadScene(std::shared_ptr<Scene> scene) {
    Globals::GetInstance().sceneReset();
    _scene = scene;
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior.second->active) behavior.second->OnStart();
        }
    }
}

void ScriptSystem::OnFrameTick(double deltaTime) {
    auto& input = Input::GetInstance();
    input.Update();
    for (auto& gameObject : activeObjects()) {
        for (auto& behavior : gameObject->behaviors) {
            if(behavior.second->active) behavior.second->OnUpdate(deltaTime);
        }
        for (auto& button : gameObject->buttons) {
            // Detect if mouse clicked on button
            if(button.second.active && input.GetMouseDown(MouseButton::LEFT) && button.second.dimensions.intersects(input.MousePosition())) {
                button.second.onClick->OnExternalEvent();
            }
        }
    }
}

void ScriptSystem::OnCloseEngine() {
    // Empty
}


