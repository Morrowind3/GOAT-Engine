#ifndef GOAT_ENGINE_DEFEATSCENE_HPP
#define GOAT_ENGINE_DEFEATSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_Menu.hpp"

using namespace Engine;

class DefeatScene : public SceneTemplate_Menu {
    public: explicit DefeatScene(Engine::SceneManager& manager);
};

#endif //GOAT_ENGINE_DEFEATSCENE_HPP
