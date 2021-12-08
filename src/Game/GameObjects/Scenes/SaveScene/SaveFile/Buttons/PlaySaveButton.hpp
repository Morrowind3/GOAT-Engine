#ifndef GOAT_ENGINE_PLAYSAVEBUTTON_HPP
#define GOAT_ENGINE_PLAYSAVEBUTTON_HPP

#include "../../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class PlaySaveButton: public GameObject {
    public: PlaySaveButton(int saveNumber, const Transform& transform, bool active);
};

#endif //GOAT_ENGINE_PLAYSAVEBUTTON_HPP
