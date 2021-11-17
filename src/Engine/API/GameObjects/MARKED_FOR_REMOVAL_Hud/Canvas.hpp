#ifndef GOAT_ENGINE_CANVAS_HPP
#define GOAT_ENGINE_CANVAS_HPP

#include "../GameObject.hpp"
#include "CanvasBehavior.hpp"
#include "UIObject.hpp"

#include <utility>
#include <vector>

namespace Engine {
    class Canvas : public GameObject {
    public:
        explicit Canvas(Transform transform, bool active, std::vector<UIObject> uiObjects);

        std::vector<UIObject> uiObjects;
    private:
        std::unique_ptr<CanvasBehavior> _canvasBehavior;
    };
}


#endif //GOAT_ENGINE_CANVAS_HPP