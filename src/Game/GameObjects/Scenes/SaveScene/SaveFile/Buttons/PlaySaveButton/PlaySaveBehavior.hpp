#ifndef GOAT_ENGINE_PLAYSAVEBEHAVIOR_HPP
#define GOAT_ENGINE_PLAYSAVEBEHAVIOR_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"

using namespace Engine;

class PlaySaveBehavior: public Behavior {
    public: PlaySaveBehavior(int saveNumber, bool active);
};

#endif //GOAT_ENGINE_PLAYSAVEBEHAVIOR_HPP
