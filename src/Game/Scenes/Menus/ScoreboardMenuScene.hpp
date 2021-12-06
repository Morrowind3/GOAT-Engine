#ifndef GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP
#define GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_Menu.hpp"

using namespace Engine;

class ScoreboardMenuScene : public SceneTemplate_Menu {
    public: explicit ScoreboardMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP
