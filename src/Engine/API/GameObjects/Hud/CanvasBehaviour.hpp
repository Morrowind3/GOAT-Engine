//
// Created by Stijn van Loon on 16-11-2021.
//

#ifndef GOAT_ENGINE_CANVASBEHAVIOUR_HPP
#define GOAT_ENGINE_CANVASBEHAVIOUR_HPP

#include "../GameComponents/Script/Script.hpp"
#include "CanvasScript.hpp"
#include "../GameComponents/Script/Behavior.hpp"
#include "UIObject.hpp"

using namespace Engine;

class CanvasBehaviour : public Behavior {
public:
    CanvasBehaviour(std::vector<UIObject>& uiObjects, bool active) : Behavior(active) {
        _canvasScript = std::make_unique<CanvasScript>(uiObjects, active);
        this->scripts.emplace_back(_canvasScript.get());
    }

private:
    std::unique_ptr<Script> _canvasScript;
};


#endif //GOAT_ENGINE_CANVASBEHAVIOUR_HPP
