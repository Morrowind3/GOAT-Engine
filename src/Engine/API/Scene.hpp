#pragma once

#include <vector>

#include "GameObjects/GameObject.hpp"
#include "Camera.hpp"

namespace Engine {
    class Scene {
        public:
            explicit Scene(std::string name);
            std::string name;
            std::vector<std::shared_ptr<GameObject>> gameObjects{};
            double width{0}, height{0}; // TODO: Use this for the camera so it doesn't go out of bounds
            void moveCamera(double x, double y);
            void moveCameraToNextWaypoint();
            [[nodiscard]] std::shared_ptr<Camera> getCamera() const;
        protected:
            Camera _camera;
    };
}
