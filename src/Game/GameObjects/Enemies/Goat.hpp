#ifndef GOAT_ENGINE_GOAT_HPP
#define GOAT_ENGINE_GOAT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

namespace GOAT {
    const std::string IDLE1 = "Idle1";
    const std::string IDLE2 = "Idle2";
    const std::string ATTACK_STANCE = "Attack Stance";
    const std::string ATTACK1 = "Attack1";
    const std::string ATTACK2 = "Attack2";
}

class Goat : public GameObject {
    public:
        Goat(Transform transform, bool active);
};


#endif //GOAT_ENGINE_GOAT_HPP
