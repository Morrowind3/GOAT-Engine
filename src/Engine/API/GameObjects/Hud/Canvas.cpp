//
// Created by Stijn van Loon on 16-11-2021.
//

#include "Canvas.hpp"
#include "CanvasBehaviour.hpp"

using namespace Engine;

Canvas::Canvas(Transform transform, bool active, std::vector<UIObject> uiObjects) :
        GameObject(transform, active), uiObjects(std::move(uiObjects)) {
    this->behaviors.push_back(CanvasBehaviour{this->uiObjects, this->active});
}
