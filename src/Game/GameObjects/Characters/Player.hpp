#ifndef GOAT_ENGINE_PLAYER_HPP
#define GOAT_ENGINE_PLAYER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

namespace PLAYER {
    const std::string IDLE = "Idle";
    const std::string MOVE1 = "Walk1";
    const std::string TEST_TEXT = "TestText";
}

class Player : public GameObject {
    public:
        explicit Player(Transform transform, bool active);
};


#endif //GOAT_ENGINE_PLAYER_HPP
