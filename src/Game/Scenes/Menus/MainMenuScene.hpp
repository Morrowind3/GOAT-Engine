#ifndef GOAT_ENGINE_MAINMENUSCENE_HPP
#define GOAT_ENGINE_MAINMENUSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_Menu.hpp"

using namespace Engine;

class MainMenuScene : public SceneTemplate_Menu {
    public: explicit MainMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_MAINMENUSCENE_HPP