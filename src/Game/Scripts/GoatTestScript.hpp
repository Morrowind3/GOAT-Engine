#ifndef GOAT_ENGINE_GOATTESTSCRIPT_HPP
#define GOAT_ENGINE_GOATTESTSCRIPT_HPP

#include "../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class GoatTestScript : public Script {
    public:
        // TODO: Reference goat class instead of game object class
        GoatTestScript(GameObject& self, bool active);
        void OnStart();
        void OnUpdate(double deltaTime);
        void OnDestroy();
    private:
        GameObject& _self;
};

#endif //GOAT_ENGINE_GOATTESTSCRIPT_HPP
