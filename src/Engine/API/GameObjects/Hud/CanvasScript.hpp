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
    CanvasScript(std::vector<UIObject>& uiObjects, bool active) : Script(active), _uiObjects(uiObjects) {};

    void OnStart() override {

    };

    void OnUpdate(double deltaTime) override {

    };

    void OnDestroy() override {

    };
private:
    std::vector<UIObject>& _uiObjects;
};

#endif //GOAT_ENGINE_CANVASSCRIPT_HPP
