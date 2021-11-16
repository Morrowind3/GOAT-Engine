#ifndef GOAT_ENGINE_GOATBEHAVIOR_HPP
#define GOAT_ENGINE_GOATBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/GoatTestScript.hpp"
#include "Scripts/AdditionalGoatTestScript.hpp"

using namespace Engine;

class GoatBehavior : public Behavior {
    public:
        GoatBehavior(GameObject& self, bool active) : Behavior(active) {
            _goatTestScript = std::make_unique<GoatTestScript>(self, true);
            scripts.emplace_back(_goatTestScript.get());
            _additionalGoatTestScript = std::make_unique<AdditionalGoatTestScript>(self, true);
            scripts.emplace_back(_additionalGoatTestScript.get());
        }
    private:
        std::unique_ptr<Script> _goatTestScript;
        std::unique_ptr<Script> _additionalGoatTestScript;
};

#endif //GOAT_ENGINE_GOATBEHAVIOR_HPP
