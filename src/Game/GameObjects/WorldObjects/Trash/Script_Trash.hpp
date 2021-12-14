#ifndef GOAT_ENGINE_SCRIPT_TRASH_HPP
#define GOAT_ENGINE_SCRIPT_TRASH_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Trash.hpp"

using namespace Engine;

class Script_Trash : public Script {
public:
    explicit Script_Trash(Object_Trash& trash, bool active): Script(active), _trash(trash){};
    void onExternalEvent() override;
    void onUpdate(double deltaTime) override;
private:
    Object_Trash& _trash;
    bool _queueForDeactivation = false;
    double _deactivationTimer = 0;
};


#endif //GOAT_ENGINE_SCRIPT_TRASH_HPP
