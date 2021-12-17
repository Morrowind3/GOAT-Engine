#ifndef GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP
#define GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_TrashCounter : public Script {
    public:
        Script_TrashCounter(Text& trashText, bool active);;
        void onUpdate(double deltaTime) override;
    private:
        // Utilities
        Globals& _globals = Globals::getInstance();
        // Variables
        Text& _text;
        std::string _total, _currentTrash;
};


#endif //GOAT_ENGINE_SCRIPT_TRASHCOUNTER_HPP
