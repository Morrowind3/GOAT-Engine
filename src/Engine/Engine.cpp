#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"
#include "Systems/ScriptSystem.hpp"
#include "Systems/AudioSystem.hpp"
#include "Utilities/Input.hpp"
#include "Utilities/Debug.hpp"

using namespace Engine;

GoatEngine::GoatEngine(SceneManager& sceneManager, std::string& name, std::string& iconPath, std::string& cursor) :
        _sceneManager{sceneManager}, _name{name}, _iconPath{iconPath}, _cursor{cursor} {
}

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
        std::shared_ptr<Scene> active = _sceneManager.CurrentScene();
        Debug::getInstance().log("Scene start: " + active->name);
        for (auto& system: *_systems) system->OnLoadScene(active);
        Debug::getInstance().log("Scene started: " + active->name);

        // Loop until scene change
        while (_isRunning && _sceneManager.CurrentScene() == active) {
            frameStart = SDL_GetTicks();
            for (auto& system: *_systems) system->OnFrameTick(deltaTime);

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
                _isRunning = false; // Quit game
            }
        }
        Debug::getInstance().log("Scene end: " + active->name);
    }

    // Destroy systems
    for (auto& system: *_systems) system->OnCloseEngine();
}
