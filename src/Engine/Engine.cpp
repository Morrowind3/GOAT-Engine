#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h" // TODO: Delegate SDL time functions to a pimpl
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Utilities/Input.hpp"
#include "Utilities/Debug.hpp"
#include <unistd.h>

using namespace Engine;

GoatEngine::GoatEngine(SceneManager& sceneManager, std::string& name, std::string& iconPath, std::string& cursor) :
        _sceneManager{sceneManager}, _name{name}, _iconPath{iconPath}, _cursor{cursor} {
}

void GoatEngine::Run(const unsigned int maxFps) {
    // Add systems
    _systems->emplace_back(std::make_unique<ScriptSystem>());
    _systems->emplace_back(std::make_unique<AudioSystem>());
    _systems->emplace_back(std::make_unique<RenderingSystem>(_name, _iconPath, _cursor));

    // Start systems
    for (auto& system: *_systems) system->OnLaunchEngine();

    // Frame variables
    const double frameDelayInMs = 1000.0/(double)maxFps;
    unsigned int currentFrameTickInMs, previousFrameTickInMs = SDL_GetTicks();
    double deltaTimeInMs {0};
    int delay {0};

    _isRunning = true;
    while (_isRunning) {

        // Load scene
        std::shared_ptr<Scene> active = _sceneManager.CurrentScene();
        Debug::GetInstance().log("Scene start: " + active->name);
        for (auto& system: *_systems) system->OnLoadScene(active);
        Debug::GetInstance().log("Scene started: " + active->name);

        // Update systems until scene change
        while (_isRunning && _sceneManager.CurrentScene() == active) {
            // Only handle frame when allowed to by the FPS cap
            currentFrameTickInMs = SDL_GetTicks();

            deltaTimeInMs = currentFrameTickInMs - previousFrameTickInMs;
            if (deltaTimeInMs >= frameDelayInMs) {
                previousFrameTickInMs = currentFrameTickInMs;
                // Perform frame logic
                for (auto& system: *_systems) system->OnFrameTick(deltaTimeInMs);
                if (Input::GetInstance().QuitEvent()) _isRunning = false; // Quit game event
            }

            // TODO: Delegate this to a script
            if(Input::GetInstance().GetKeyDown(Input::KeyCode::RIGHT)) {
                delay += 10000;
            }
            if(Input::GetInstance().GetKeyDown(Input::KeyCode::LEFT)) {
                if(delay -10000 >= 0) {
                    delay -= 10000;
                }
            }
            if(delay > 0) {
                usleep(delay);
            }
            // ~TODO: Delegate this to a script

        }
        Debug::GetInstance().log("Scene end: " + active->name);
    }

    // Destroy systems
    for (auto& system: *_systems) system->OnCloseEngine();
}