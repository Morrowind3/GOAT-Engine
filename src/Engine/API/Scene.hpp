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
            void MoveCamera(double x, double y);
            void MoveCameraToNextWaypoint();
            [[nodiscard]] std::shared_ptr<Camera> GetCamera() const;
        protected:
            Camera _camera;
    };
}
