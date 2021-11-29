#include "Engine.hpp"

#include "Systems/RenderingSystem.hpp"
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Systems/CollisionSystem.hpp"

using namespace Engine;

GoatEngine::GoatEngine(SceneManager& sceneManager, std::string& name, std::string& iconPath, std::string& cursor) :
        _sceneManager{sceneManager}, _name{name}, _iconPath{iconPath}, _cursor{cursor} {
}

void GoatEngine::run(const unsigned int maxFps) {
    _clock.setFps(maxFps);

    // Add systems
    _systems->emplace_back(std::make_unique<CollisionSystem>());
    _systems->emplace_back(std::make_unique<ScriptSystem>());
    _systems->emplace_back(std::make_unique<AudioSystem>());
    _systems->emplace_back(std::make_unique<RenderingSystem>(_name, _iconPath, _cursor));

    // Start systems
    for (auto& system: *_systems) system->onLaunchEngine();

    _isRunning = true;
    while (_isRunning) {
        // Load scene
        std::shared_ptr<Scene> active = _sceneManager.currentScene();
        _debug.log("Scene start: " + active->name);
        for (auto& system: *_systems) system->onLoadScene(active);
        _debug.log("Scene started: " + active->name);

        // Update systems until scene change
        while (_isRunning && _sceneManager.currentScene() == active) {
            // Only handle frame when allowed to by the FPS cap
            if (_clock.tickAndCheckIfNextFrameIsReady()) {
                // Perform frame logic
                for (auto& system: *_systems) system->onFrameTick(_clock.gameStateBasedDeltaTime());
                if (_engineCalls.quitEventQueued()) _isRunning = false; // Quit game event
                _sceneManager.currentScene()->moveCameraToNextWaypoint();
            }
        }
        _debug.log("Scene end: " + active->name);
    }

    // Destroy systems
    for (auto& system: *_systems) system->onCloseEngine();
}