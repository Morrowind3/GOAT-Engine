#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"

using namespace Engine;

GoatEngine::GoatEngine() :
        _isRunning{false},
        _systems{std::make_unique<std::vector<std::unique_ptr<System>>>()} {}

void GoatEngine::Run() {
    // add systems
    _systems->emplace_back(std::make_unique<RenderingSystem>(_sceneManager.CurrentScene()));

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    unsigned int frameStart;
    unsigned int frameTime;

    // Start systems
    for (auto& system: *_systems) system->OnInit();
    _isRunning = true;

    // Update systems
    unsigned int ticks = 0;
    while (_isRunning) {
        std::cout << "Tick number " << ++ticks << "/100" << '\n';
        frameStart = SDL_GetTicks();

        for (auto& system: *_systems) system->OnUpdate();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        // TODO: Replace with script
        // Prove that movement is possible
        for (auto& gameObject: _sceneManager.CurrentScene()->_gameObjects) {
            gameObject.transform._position.x += 1.0;
            gameObject.transform._position.y += 1.0;
        }

        if (ticks == 100) {
            _isRunning = false;
        }
    }

    // Destroy systems
    for (auto& system: *_systems) system->OnDestroy();
}
