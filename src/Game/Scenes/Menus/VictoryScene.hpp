#ifndef GOAT_ENGINE_VICTORYSCENE_HPP
#define GOAT_ENGINE_VICTORYSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_Menu.hpp"

using namespace Engine;

class VictoryScene : public SceneTemplate_Menu {
    public: explicit VictoryScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_VICTORYSCENE_HPP
