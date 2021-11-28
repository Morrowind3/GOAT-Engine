#ifndef GOAT_ENGINE_DEFEATBACKGROUND_HPP
#define GOAT_ENGINE_DEFEATBACKGROUND_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class DefeatBackground : public GameObject {
    public: DefeatBackground(Transform transform, bool active);
};

#endif //GOAT_ENGINE_DEFEATBACKGROUND_HPP
