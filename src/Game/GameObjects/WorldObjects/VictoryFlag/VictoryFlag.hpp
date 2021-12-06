#ifndef GOAT_ENGINE_VICTORYFLAG_HPP
#define GOAT_ENGINE_VICTORYFLAG_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class VictoryFlag : public GameObject {
    public: VictoryFlag(Transform transform, bool active);
};


#endif //GOAT_ENGINE_VICTORYFLAG_HPP
