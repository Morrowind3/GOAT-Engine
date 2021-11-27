//
// Created by Morrowind3 on 27/11/2021.
//

#ifndef GOAT_ENGINE_GAMESTATESCRIPT_HPP
#define GOAT_ENGINE_GAMESTATESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;

class GameStateScript : public Script {
    public:
        GameStateScript(SceneManager& sceneManager, bool active) : Script(active), _sceneManager(sceneManager){};
        void OnUpdate(double deltaTime) override;
    private:
        SceneManager& _sceneManager;
        void GameLost();
        void GameWon();
};


#endif //GOAT_ENGINE_GAMESTATESCRIPT_HPP
