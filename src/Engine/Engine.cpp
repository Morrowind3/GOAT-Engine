#include <iostream>
#include "Engine.hpp"
#include "Systems/RenderingSystem.hpp"

#include "SDL_image.h"

Engine::Engine(const SceneManager& scenes) :
	_isRunning { false },
	_sceneManager { std::make_unique<SceneManager>(scenes) },
	_systems { std::make_unique<std::vector<std::unique_ptr<System>>>() },
    _scene { std::make_unique<Scene>(_sceneManager->Current()) }
{	
	_systems->emplace_back(std::make_unique<RenderingSystem>(_scene.get()));
}

void Engine::Run() {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	unsigned int frameStart;
	unsigned int frameTime;

	// Start systems
	for (auto & system : *_systems) system->OnInit();
	_isRunning = true;

	// Update systems
    unsigned int ticks = 0;
	while (_isRunning) {
        std::cout << "Tick number " << ++ticks << "/100" << '\n';
		frameStart = SDL_GetTicks();

		for (auto & system : *_systems) system->OnUpdate();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

        // Prove that movement is possible
        for(auto & gameObject : _scene->_gameObjects) {
            gameObject.transform.position.x+=1.0;
            gameObject.transform.position.y+=1.0;
        }

        if (ticks == 100) {
            _isRunning = false;
        }
	}

	// Destroy systems
	for (auto & system : *_systems) system->OnDestroy();
}
