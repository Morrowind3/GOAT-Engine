#ifndef GOAT_ENGINE_TRASHSCRIPT_HPP
#define GOAT_ENGINE_TRASHSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Trash.hpp"

using namespace Engine;

class TrashScript : public Script {
public:
    explicit TrashScript(Trash& trash, bool active): Script(active), _trash(trash){};
    void onExternalEvent() override;
    void onUpdate(double deltaTime) override;
private:
    Trash& _trash;
    bool _queueForDeactivation = false;
    double _deactivationTimer = 0;
};


#endif //GOAT_ENGINE_TRASHSCRIPT_HPP
