#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Utilities/Input.hpp"

using namespace Engine;

GoatEngine::GoatEngine(std::string& name, std::string& iconPath) :
        _isRunning{false},
        _systems{std::make_unique<std::vector<std::unique_ptr<System>>>()},
        _name(name),
        _iconPath(iconPath) {}

void GoatEngine::Run() {
    // Add systems
    _systems->emplace_back(std::make_unique<RenderingSystem>(sceneManager.CurrentScene(), _name, _iconPath));
    _systems->emplace_back(std::make_unique<ScriptSystem>(sceneManager.CurrentScene()));
    _systems->emplace_back(std::make_unique<AudioSystem>(sceneManager.CurrentScene()));

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

        double xCamMovement = 0, yCamMovement = 0;
        if(Input::GetInstance().GetKeyDown(Input::KeyCode::RIGHT)){
            xCamMovement += 20;
        }
        if(Input::GetInstance().GetKeyDown(Input::KeyCode::LEFT)){
            xCamMovement -= 20;
        }
        if(Input::GetInstance().GetKeyDown(Input::KeyCode::UP)){
            yCamMovement -= 20;
        }
        if(Input::GetInstance().GetKeyDown(Input::KeyCode::DOWN)){
            yCamMovement += 20;
        }
        sceneManager.CurrentScene()->MoveCamera(xCamMovement,yCamMovement);



        for (auto& system: *_systems) system->OnUpdate(deltaTime);

        frameTime = SDL_GetTicks() - frameStart;
        deltaTime = (double)frameTime*1000/(double)SDL_GetPerformanceFrequency();
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        if (Input::GetInstance().QuitEvent()) {
            _isRunning = false;
            exit(0);
        }
    }

    // TODO: It hangs here
    // Destroy systems
    for (auto& system: *_systems) system->OnDestroy();
}
