#ifndef GOAT_ENGINE_GOATTESTSCRIPT_HPP
#define GOAT_ENGINE_GOATTESTSCRIPT_HPP

#include "../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class GoatTestScript : public Script {
    public:
        GoatTestScript(GameObject& self, bool active);
        void OnStart() override;
        void OnUpdate(double deltaTime) override;
        void OnDestroy() override;
    private:
        GameObject& _self;
};

#endif //GOAT_ENGINE_GOATTESTSCRIPT_HPP
