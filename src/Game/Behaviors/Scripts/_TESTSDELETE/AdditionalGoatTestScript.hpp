#ifndef GOAT_ENGINE_ADDITIONALGOATTESTSCRIPT_HPP
#define GOAT_ENGINE_ADDITIONALGOATTESTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class AdditionalGoatTestScript : public Script {
    public:
        // TODO: Reference goat class instead of game object class
        AdditionalGoatTestScript(GameObject& self, bool active);
        void OnUpdate(double deltaTime);
    private:
        GameObject& _self;
};


#endif //GOAT_ENGINE_ADDITIONALGOATTESTSCRIPT_HPP
