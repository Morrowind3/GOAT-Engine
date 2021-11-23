#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Utilities/Input.hpp"

using namespace Engine;

GoatEngine::GoatEngine(std::string& name, std::string& iconPath, std::string& cursor) :
        _isRunning{false},
        _systems{std::make_unique<std::vector<std::unique_ptr<System>>>()},
        _name(name),
        _iconPath(iconPath),
        _cursor(cursor) {}

void GoatEngine::Run(const unsigned int maxFps) {
    // Frame variables
    const unsigned int frameDelay = 1000 / maxFps;
    unsigned int frameStart, frameTime;
    double deltaTime = 0;

    // Add systems
    _systems->emplace_back(std::make_unique<ScriptSystem>());
    _systems->emplace_back(std::make_unique<AudioSystem>());
    _systems->emplace_back(std::make_unique<RenderingSystem>(_name, _iconPath, _cursor));

    // Start systems
    for (auto& system: *_systems) system->OnLaunchEngine();

    // Update systems
    _isRunning = true;
    while (_isRunning) {

        // Load scene
        Scene* active = sceneManager.CurrentScene();
        for (auto& system: *_systems) system->OnLoadScene(active);

        // Loop until scene change
        while (_isRunning && sceneManager.CurrentScene() == active) {
            frameStart = SDL_GetTicks();

            for (auto& system: *_systems) system->OnFrameTick(deltaTime);

            frameTime = SDL_GetTicks() - frameStart;
            deltaTime = (double)frameTime*1000/(double)SDL_GetPerformanceFrequency();
            if (frameDelay > frameTime) {
                SDL_Delay(frameDelay - frameTime);
            }

            if (Input::getInstance().QuitEvent()) {
                _isRunning = false; // Quit game
            }
        }
    }

    // Destroy systems
    for (auto& system: *_systems) system->OnCloseEngine();
}
