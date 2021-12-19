#ifndef GOAT_ENGINE_OBJECT_PLAYSAVEBUTTON_HPP
#define GOAT_ENGINE_OBJECT_PLAYSAVEBUTTON_HPP

#include "../../../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_PlaySaveButton: public GameObject {
    public: Object_PlaySaveButton(int saveNumber, const Transform& transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_PLAYSAVEBUTTON_HPP
