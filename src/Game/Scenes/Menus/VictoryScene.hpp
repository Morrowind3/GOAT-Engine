#ifndef GOAT_ENGINE_VICTORYSCENE_HPP
#define GOAT_ENGINE_VICTORYSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class VictoryScene : public SceneTemplate_StaticScreen {
    public: explicit VictoryScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_VICTORYSCENE_HPP
