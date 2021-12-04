#ifndef GOAT_ENGINE_DEFEATSCENE_HPP
#define GOAT_ENGINE_DEFEATSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class DefeatScene : public SceneTemplate_StaticScreen {
    public: explicit DefeatScene(Engine::SceneManager& manager);
};

#endif //GOAT_ENGINE_DEFEATSCENE_HPP
