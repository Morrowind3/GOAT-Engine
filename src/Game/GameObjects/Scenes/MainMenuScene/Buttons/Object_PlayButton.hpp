#ifndef GOAT_ENGINE_OBJECT_PLAYBUTTON_HPP
#define GOAT_ENGINE_OBJECT_PLAYBUTTON_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_PlayButton : public GameObject {
    public: Object_PlayButton(Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_PLAYBUTTON_HPP
