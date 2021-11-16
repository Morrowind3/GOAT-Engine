#ifndef GOAT_ENGINE_CANVAS_HPP
#define GOAT_ENGINE_CANVAS_HPP

#include "GameObjects/GameComponents/GameComponent.hpp"
#include "GameObjects/GameComponents/Hud/UIObject.hpp"

#include <utility>
#include <vector>

namespace Engine {
    class Canvas : public GameComponent {
    public:
        explicit Canvas(float width, float height, std::vector<UIObject> uiObjects);

        std::vector<UIObject> uiObjects;
        float width;
        float height;

        void OnStart();

        void OnUpdate(double deltaTime);

        void OnDestroy();
    };
}


#endif //GOAT_ENGINE_CANVAS_HPP
