#ifndef GOAT_ENGINE_THIRDTESTSCRIPT_HPP
#define GOAT_ENGINE_THIRDTESTSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class ThirdTestScript : public Script {
    public:
        explicit ThirdTestScript(bool active);
        void OnUpdate(double deltaTime);
    private:
        size_t _counter {0};
};


#endif //GOAT_ENGINE_THIRDTESTSCRIPT_HPP
