//
// Created by Morrowind3 on 27/11/2021.
//

#ifndef GOAT_ENGINE_GAMESTATEMANAGER_HPP
#define GOAT_ENGINE_GAMESTATEMANAGER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class GameStateManager : public GameObject {
public:
    GameStateManager(SceneManager& sceneManager, bool active);
private:
};


#endif //GOAT_ENGINE_GAMESTATEMANAGER_HPP
