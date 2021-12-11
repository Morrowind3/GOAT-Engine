#ifndef GOAT_ENGINE_PLAYBUTTON_HPP
#define GOAT_ENGINE_PLAYBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class PlayButton : public GameObject {
    public: PlayButton(Transform transform, bool active);
};

#endif //GOAT_ENGINE_PLAYBUTTON_HPP
