#include "ScriptSystem.hpp"

using namespace Engine;

ScriptSystem::ScriptSystem(const Scene* scene) : System(scene) {
}

void ScriptSystem::OnInit() {
    for (auto &gameObject : _scene->_gameObjects) {
        for (auto &script : gameObject->scripts) {
            script->OnStart();
        }
    }
}

void ScriptSystem::OnUpdate() {
    for (auto &gameObject : _scene->_gameObjects) {
        for (auto &script : gameObject->scripts) {
            script->OnUpdate(0); // TODO: DeltaTime magic
        }
    }
}

void ScriptSystem::OnDestroy() {
    for (auto &gameObject : _scene->_gameObjects) {
        for (auto &script : gameObject->scripts) {
            script->OnDestroy();
        }
    }
}
