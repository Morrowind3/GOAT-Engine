#include "ScriptSystem.hpp"

using namespace Engine;

void ScriptSystem::onLaunchEngine() {
    _debug.log("Script system launch"); // Empty
}

void ScriptSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Script system load");
    _globals.sceneReset();
    _scene = scene;
    auto active = activeObjects();
    runOnStarts(active);
}

void ScriptSystem::onFrameTick(const double deltaTime) {
    _input.update();
    destroyObjectsMarkedForDestruction();
    _physics.runCollisionScripts();
    auto active = activeObjects();
    runOnStarts(active);
    runPressedButtons(active);
    runOnDestroys(active);
    runOnUpdates(active, deltaTime);
    markObjectsForDestruction();
}

void ScriptSystem::onCloseEngine() {
    _debug.log("Script system close"); // Empty
}

void ScriptSystem::runOnStarts(std::vector<std::shared_ptr<GameObject>>& activeObjects) {
    for (auto& gameObject: activeObjects) {
        for (auto& behavior : gameObject->behaviors) {
            if (behavior.second->active && !behavior.second->_onStartCalled) {
                behavior.second->_onStartCalled = true;
                behavior.second->onStart();
            }
        }
    }
    LuaHelper::execute("LuaScripts/test.lua");
}

void ScriptSystem::runOnUpdates(std::vector<std::shared_ptr<GameObject>>& activeObjects, const double deltaTime) {
    for (auto& gameObject: activeObjects) {
        for (auto& behavior: gameObject->behaviors) {
            if(behavior.second->active) behavior.second->onUpdate(deltaTime);
        }
    }
}

bool ScriptSystem::buttonPressed(const Rectangle& buttonDimensions) {
    return _input.anyMouseDown() && buttonDimensions.intersects(_input.mousePosition());
}

void ScriptSystem::runPressedButtons(std::vector<std::shared_ptr<GameObject>>& activeObjects) {
    for (auto& gameObject: activeObjects) {
        for (auto& button: gameObject->buttons) {
            // Detect if mouse clicked on button
            if(button.second.active && button.second.onClick->active && buttonPressed(button.second.dimensions)) {
                button.second.onClick->onExternalEvent();
            }
        }
    }
}

void ScriptSystem::runOnDestroys(std::vector<std::shared_ptr<GameObject>>& activeObjects) {
    for (auto& gameObject: activeObjects) {
        if (gameObject->queueForDestruction) {
            for (auto& behavior: gameObject->behaviors) {
                if(behavior.second->active) behavior.second->onDestroy();
            }
        }
    }
}

void ScriptSystem::markObjectsForDestruction() {
    for (auto& gameObject: _scene->gameObjects) {
        if (gameObject->queueForDestruction) gameObject->_destroyNextTick = true;
    }
}

void ScriptSystem::destroyObjectsMarkedForDestruction() {
    for (int position = 0; position < _scene->gameObjects.size(); ++position) {
        auto gameObject = _scene->gameObjects.at(position);
        if (gameObject->_destroyNextTick) {
            gameObject->active = false;
            _graveyard.emplace_back(gameObject);
            _scene->gameObjects.erase(_scene->gameObjects.begin()+position);
        }
    }
}

