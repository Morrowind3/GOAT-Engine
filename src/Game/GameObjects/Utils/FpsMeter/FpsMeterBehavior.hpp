#ifndef GOAT_ENGINE_FPSMETERBEHAVIOR_HPP
#define GOAT_ENGINE_FPSMETERBEHAVIOR_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class FpsMeterBehavior : public Behavior {
    public: FpsMeterBehavior(Text& fpsText, bool active);
};


#endif //GOAT_ENGINE_FPSMETERBEHAVIOR_HPP
