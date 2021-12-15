#ifndef GOAT_ENGINE_SCRIPT_ANIMATECREDITSTEXT_HPP
#define GOAT_ENGINE_SCRIPT_ANIMATECREDITSTEXT_HPP

#include <vector>
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Script_AnimateCreditsText: public Script {
    public:
        Script_AnimateCreditsText(std::vector<Text*> creditsText, bool active);
        void onUpdate(double deltaTime) override;
    private:
        // Variables
        std::vector<Text*> _creditsText;
        int _originalPosition;
        bool moveToRight {false};
        // Constants
        const int MAXIMUM_DIFFERENCE {320};
};


#endif //GOAT_ENGINE_SCRIPT_ANIMATECREDITSTEXT_HPP
