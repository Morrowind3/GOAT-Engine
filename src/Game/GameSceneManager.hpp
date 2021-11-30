#ifndef GOAT_ENGINE_GAMESCENEMANAGER_HPP
#define GOAT_ENGINE_GAMESCENEMANAGER_HPP

#include "../Engine/SceneManager.hpp"

using namespace Engine;

class GameSceneManager : public SceneManager {
    public: void changeCurrentScene(const std::string& name) override;
    private:
        int _currentEtappe{0};
        void setEtappeScene();
};


#endif //GOAT_ENGINE_GAMESCENEMANAGER_HPP
