#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"
#include "Systems/ScriptSystem.hpp"
#include "Utilities/Input.hpp"

using namespace Engine;

GoatEngine::GoatEngine() :
        _isRunning{false},
        _systems{std::make_unique<std::vector<std::unique_ptr<System>>>()} {}

void GoatEngine::Run() {
    // Add systems
    _systems->emplace_back(std::make_unique<RenderingSystem>(sceneManager.CurrentScene()));
    _systems->emplace_back(std::make_unique<ScriptSystem>(sceneManager.CurrentScene()));

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    unsigned int frameStart;
    unsigned int frameTime;
    double deltaTime = 0;

    // Start systems
    for (auto& system: *_systems) system->OnInit();
    _isRunning = true;

    // Update systems
    while (_isRunning) {
        frameStart = SDL_GetTicks();

        for (auto& system: *_systems) system->OnUpdate(deltaTime);

        frameTime = SDL_GetTicks() - frameStart;
        deltaTime = (double)frameTime*1000/(double)SDL_GetPerformanceFrequency();
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        if (Input::getInstance().QuitEvent()) {
            _isRunning = false;
        }
    }

    // Destroy systems
    for (auto& system: *_systems) system->OnDestroy();
}
