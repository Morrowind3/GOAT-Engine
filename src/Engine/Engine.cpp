#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h" // TODO: Delegate SDL time functions to a pimpl
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Utilities/Input.hpp"
#include "Utilities/Debug.hpp"
#include <unistd.h>
#include "Systems/CollisionSystem.hpp"

using namespace Engine;

GoatEngine::GoatEngine(SceneManager& sceneManager, std::string& name, std::string& iconPath, std::string& cursor) :
        _sceneManager{sceneManager}, _name{name}, _iconPath{iconPath}, _cursor{cursor} {
}

void GoatEngine::run(const unsigned int maxFps) {
    // Add systems
    _systems->emplace_back(std::make_unique<CollisionSystem>());
    _systems->emplace_back(std::make_unique<ScriptSystem>());
    _systems->emplace_back(std::make_unique<AudioSystem>());
    _systems->emplace_back(std::make_unique<RenderingSystem>(_name, _iconPath, _cursor));

    // Start systems
    for (auto& system: *_systems) system->onLaunchEngine();

    // Frame variables
    const double frameDelayInMs = 1000.0/(double)maxFps;
    unsigned int currentFrameTickInMs, previousFrameTickInMs = SDL_GetTicks();
    double deltaTimeInMs {0};
    int delay {0};

    _isRunning = true;
    while (_isRunning) {

        // Load scene
        std::shared_ptr<Scene> active = _sceneManager.currentScene();
        Debug::getInstance().log("Scene start: " + active->name);
        for (auto& system: *_systems) system->onLoadScene(active);
        Debug::getInstance().log("Scene started: " + active->name);

        // Update systems until scene change
        while (_isRunning && _sceneManager.currentScene() == active) {
            // Only handle frame when allowed to by the FPS cap
            currentFrameTickInMs = SDL_GetTicks();

            deltaTimeInMs = currentFrameTickInMs - previousFrameTickInMs;
            if (deltaTimeInMs >= frameDelayInMs) {
                previousFrameTickInMs = currentFrameTickInMs;
                // Perform frame logic
                for (auto& system: *_systems) system->onFrameTick(deltaTimeInMs);
                if (Input::getInstance().quitEvent()) _isRunning = false; // Quit game event
                _sceneManager.currentScene()->moveCameraToNextWaypoint();
            }

            // TODO: Delegate this to a script
            if(Input::getInstance().getKeyDown(KeyCode::RIGHT)) {
                delay += 10000;
            }
            if(Input::getInstance().getKeyDown(KeyCode::LEFT)) {
                if(delay -10000 >= 0) {
                    delay -= 10000;
                }
            }
            if(delay > 0) {
                usleep(delay);
            }
            // ~TODO: Delegate this to a script

        }
        Debug::getInstance().log("Scene end: " + active->name);
    }

    // Destroy systems
    for (auto& system: *_systems) system->onCloseEngine();
}