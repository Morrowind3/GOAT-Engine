//
// Created by Stijn van Loon on 16-11-2021.
//

#include "Canvas.hpp"

using namespace Engine;

Canvas::Canvas(Transform transform, bool active, std::vector<UIObject> uiObjects) :
        GameObject(transform, active), uiObjects(std::move(uiObjects)) {
    _canvasBehavior = std::make_unique<CanvasBehavior>(this->uiObjects, this->active);
    this->behaviors.push_back(*_canvasBehavior);
}
