#ifndef GOAT_ENGINE_BEHAVIOR_PLAYSAVE_HPP
#define GOAT_ENGINE_BEHAVIOR_PLAYSAVE_HPP

#include "../../../../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"

using namespace Engine;

class Behavior_PlaySave: public Behavior {
    public: Behavior_PlaySave(int saveNumber, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_PLAYSAVE_HPP
