#ifndef GOAT_ENGINE_GAMESCENEMANAGER_HPP
#define GOAT_ENGINE_GAMESCENEMANAGER_HPP

#include "../Engine/SceneManager.hpp"

using namespace Engine;

class GameSceneManager : public SceneManager {
    public: void ChangeCurrentScene(const std::string& name) override;
};


#endif //GOAT_ENGINE_GAMESCENEMANAGER_HPP
