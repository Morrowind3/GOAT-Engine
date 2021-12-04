#ifndef GOAT_ENGINE_SCENE_HPP
#define GOAT_ENGINE_SCENE_HPP

#include <vector>

#include "GameObjects/GameObject.hpp"
#include "Camera.hpp"

namespace Engine {
    class Scene {
        public:
            Scene(std::string name, Point dimensions, Rectangle viewPort);
            std::vector<std::shared_ptr<GameObject>> gameObjects{};
            // TODO: Encapsulate these values
            Point dimensions;
            Rectangle viewPort;
            std::string name;

            [[maybe_unused]] void moveCamera(double x, double y);
            void moveCameraToNextWaypoint();
            [[nodiscard]] std::shared_ptr<Camera> getCamera() const;
        protected:
            Camera _camera;
    };
}

#endif //GOAT_ENGINE_SCENE_HPP
