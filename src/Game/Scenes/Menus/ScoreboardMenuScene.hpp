#ifndef GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP
#define GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP

#include "../../../Engine/SceneManager.hpp"
#include "../Templates/SceneTemplate_StaticScreen.hpp"

using namespace Engine;

class ScoreboardMenuScene : public SceneTemplate_StaticScreen {
    public: explicit ScoreboardMenuScene(SceneManager& manager);
};

#endif //GOAT_ENGINE_SCOREBOARDMENUSCENE_HPP
