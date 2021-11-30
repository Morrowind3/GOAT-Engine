#ifndef GOAT_ENGINE_SCOREBOARDBUTTON_HPP
#define GOAT_ENGINE_SCOREBOARDBUTTON_HPP

#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class ScoreboardButton : public GameObject {
    public: ScoreboardButton(SceneManager& sceneManager, Transform transform, bool active);
};

#endif //GOAT_ENGINE_SCOREBOARDBUTTON_HPP
