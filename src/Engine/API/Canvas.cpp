//
// Created by Stijn van Loon on 16-11-2021.
//

#include "Canvas.hpp"

using namespace Engine;

Canvas::Canvas(float width, float height, std::vector<UIObject> uiObjects) :
        GameComponent(true), uiObjects(std::move(uiObjects)), width(width), height(height) {}

void Canvas::OnStart() {
    for (const auto& item: this->uiObjects) {

    }
}

void Canvas::OnUpdate(double deltaTime) {

}

void Canvas::OnDestroy() {

}