#ifndef GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP
#define GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class SwitchSceneButtonScript : public Script {
    public:
        SwitchSceneButtonScript(std::string levelName, SceneManager& sceneManager, bool active);
        void onExternalEvent();
    private:
        SceneManager& _sceneManager;
        std::string _levelName;
};


#endif //GOAT_ENGINE_SWITCHSCENEBUTTONSCRIPT_HPP
