#ifndef GOAT_ENGINE_ADDITIONALBEHAVIOR_HPP
#define GOAT_ENGINE_ADDITIONALBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/ThirdTestScript.hpp"

using namespace Engine;

class AdditionalBehavior : public Behavior {
    public:
        AdditionalBehavior(bool active) : Behavior(active) {
                _thirdTestScript = std::make_unique<ThirdTestScript>(true);
                scripts.emplace_back(_thirdTestScript.get());
        }
    private:
        std::unique_ptr<Script> _thirdTestScript;
};

#endif //GOAT_ENGINE_ADDITIONALBEHAVIOR_HPP
