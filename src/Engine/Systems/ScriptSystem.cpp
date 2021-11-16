#include "ScriptSystem.hpp"
#include "../Utilities/Input.hpp"

using namespace Engine;

ScriptSystem::ScriptSystem(const Scene* scene) : System(scene) {
}

void ScriptSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior.OnStart();
        }
    }
}

void ScriptSystem::OnUpdate(double deltaTime) {
    Input::getInstance().Update();
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior.OnUpdate(deltaTime);
        }
    }
}

void ScriptSystem::OnDestroy() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& behavior : gameObject->behaviors) {
            behavior.OnDestroy();
        }
    }
}
