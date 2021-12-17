#ifndef GOAT_ENGINE_SCRIPT_TRASH_HPP
#define GOAT_ENGINE_SCRIPT_TRASH_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Trash.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_Trash : public Script {
    public:
        Script_Trash(Object_Trash& trash, bool active);
        void onStart() override;
        void onExternalEvent() override;
    private:
        // Utilities
        Globals& _globals = Globals::getInstance();
        // Variables
        Object_Trash& _trash;
};


#endif //GOAT_ENGINE_SCRIPT_TRASH_HPP
