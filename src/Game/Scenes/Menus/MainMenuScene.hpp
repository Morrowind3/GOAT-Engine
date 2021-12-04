#ifndef GOAT_ENGINE_MAINMENUSCENE_HPP
#define GOAT_ENGINE_MAINMENUSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class MainMenuScene : public SceneTemplate_StaticScreen {
    public: explicit MainMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_MAINMENUSCENE_HPP
