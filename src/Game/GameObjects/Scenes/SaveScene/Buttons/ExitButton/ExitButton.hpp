#ifndef GOAT_ENGINE_EXITBUTTON_HPP
#define GOAT_ENGINE_EXITBUTTON_HPP

#include "../../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class ExitButton : public GameObject {
    public: ExitButton(Transform transform, bool active);
};


#endif //GOAT_ENGINE_EXITBUTTON_HPP
