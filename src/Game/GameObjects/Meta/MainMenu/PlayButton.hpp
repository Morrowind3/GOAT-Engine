#ifndef GOAT_ENGINE_PLAYBUTTON_HPP
#define GOAT_ENGINE_PLAYBUTTON_HPP

#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class PlayButton : public GameObject {
    public: PlayButton(SceneManager& sceneManager, Transform transform, bool active);
};

#endif //GOAT_ENGINE_PLAYBUTTON_HPP
