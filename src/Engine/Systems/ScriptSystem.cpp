#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"

using namespace Engine;

ScriptSystem::ScriptSystem(const Scene* scene) : System(scene) {
}

void ScriptSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior->OnStart();
        }
    }
}

void ScriptSystem::OnUpdate(double deltaTime) {
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

void ScriptSystem::OnDestroy() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior->OnDestroy();
        }
    }
}
