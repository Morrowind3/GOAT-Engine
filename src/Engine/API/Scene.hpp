#ifndef GOAT_ENGINE_SCENE_HPP
#define GOAT_ENGINE_SCENE_HPP

#include <vector>

#include "GameObjects/GameObject.hpp"
#include "Camera.hpp"

namespace Engine {
    class Scene {
        public:
            explicit Scene(std::string name);
            std::vector<std::shared_ptr<GameObject>> gameObjects{};
            // TODO: These two values mandatory in the constructor
            Point dimensions = {1920,985};
            Rectangle viewPort = {{0,0},960,493};
            std::string name;

            [[maybe_unused]] void moveCamera(double x, double y);
            void moveCameraToNextWaypoint();
            [[nodiscard]] std::shared_ptr<Camera> getCamera() const;
        protected:
            Camera _camera;
    };
}

#endif //GOAT_ENGINE_SCENE_HPP
