//
// Created by Stijn van Loon on 16-11-2021.
//

#ifndef GOAT_ENGINE_CANVASSCRIPT_HPP
#define GOAT_ENGINE_CANVASSCRIPT_HPP

#include "../GameComponents/Script/Script.hpp"
#include "UIObject.hpp"
#include <iostream>

using namespace Engine;

class CanvasScript : public Script {
public:
    CanvasScript(bool active, std::vector<UIObject>& uiObjects) : Script(active), _uiObjects(uiObjects) {};

    void OnStart() {
        for (const auto &obj : _uiObjects) {

        }
    };

    void OnUpdate(double deltaTime) {

    };

    void OnDestroy() {

    };
private:
    std::vector<UIObject>& _uiObjects;
};

#endif //GOAT_ENGINE_CANVASSCRIPT_HPP
