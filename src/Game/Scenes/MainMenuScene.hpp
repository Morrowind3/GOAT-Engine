#ifndef GOAT_ENGINE_MAINMENUSCENE_HPP
#define GOAT_ENGINE_MAINMENUSCENE_HPP

#include "../Keys.hpp"
#include "../../Engine/API/Scene.hpp"
#include "../../Engine/SceneManager.hpp"

using namespace Engine;

class MainMenuScene : public Scene {
    public: explicit MainMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_MAINMENUSCENE_HPP
