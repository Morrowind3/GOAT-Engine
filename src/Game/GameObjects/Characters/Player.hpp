#ifndef GOAT_ENGINE_PLAYER_HPP
#define GOAT_ENGINE_PLAYER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

namespace PLAYER {
    const std::string IDLE = "Idle";
    const std::string MOVE1 = "Walk1";
    const std::string JUMP = "Jump";
    const std::string TEST_TEXT = "TestText";
    const std::string JUMP_SFX = "JumpSfx";
    const std::string WALK_SFX_A = "WalkSfx";
    const std::string WALK_SFX_B = "WalkSfxB";
}

class Player : public GameObject {
    public:
        explicit Player(Transform transform, bool active);
};


#endif //GOAT_ENGINE_PLAYER_HPP
