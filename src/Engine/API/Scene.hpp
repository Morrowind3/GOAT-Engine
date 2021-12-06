#ifndef GOAT_ENGINE_SCENE_HPP
#define GOAT_ENGINE_SCENE_HPP

#include <vector>

#include "GameObjects/GameObject.hpp"
#include "Camera.hpp"
#include "LayerGroup.hpp"

namespace Engine {
    class Scene {
        public:
            Scene(std::string name, Point dimensions, Rectangle viewPort);
            std::vector<std::shared_ptr<GameObject>> gameObjects{};
            // Key determines which layer group gets rendered first (0 = bottom/first, 0xffffffff = on top/last)
            std::map<unsigned int, LayerGroup> layerGroups{};

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
