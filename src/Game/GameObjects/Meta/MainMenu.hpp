#ifndef GOAT_ENGINE_MAINMENU_HPP
#define GOAT_ENGINE_MAINMENU_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../Keys.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class MainMenu : public GameObject {
    public: MainMenu(SceneManager& sceneManager, Transform transform, bool active);
};


#endif //GOAT_ENGINE_MAINMENU_HPP
