#ifndef GOAT_ENGINE_CANVASBEHAVIOR_HPP
#define GOAT_ENGINE_CANVASBEHAVIOR_HPP

#include "../GameComponents/Script/Script.hpp"
#include "CanvasScript.hpp"
#include "../GameComponents/Script/Behavior.hpp"
#include "UIObject.hpp"

using namespace Engine;

class CanvasBehavior : public Behavior {
public:
    CanvasBehavior(std::vector<UIObject>& uiObjects, bool active) : Behavior(active) {
        _canvasScript = std::make_unique<CanvasScript>(active, uiObjects);

        this->scripts.push_back(_canvasScript.get());
    }

private:
    std::unique_ptr<Script> _canvasScript;
};


#endif //GOAT_ENGINE_CANVASBEHAVIOR_HPP
