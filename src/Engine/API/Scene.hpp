#ifndef GOAT_ENGINE_SCENE_HPP
#define GOAT_ENGINE_SCENE_HPP

#include <vector>

#include "Camera.hpp"

namespace Engine {
    class Scene {
        public:
            Scene(std::string name, Point dimensions, Rectangle viewPort);
            std::vector<std::shared_ptr<GameObject>> gameObjects{};
            // Key determines which layer group gets rendered first (0 = bottom/first, 0xffffffff = on top/last)
            std::map<unsigned int, LayerGroup> layerGroups{};

            [[nodiscard]] std::shared_ptr<Camera> getCamera() const;
            [[nodiscard]] const std::string& getName() const;
            [[nodiscard]] const Rectangle& getViewPort() const;
        protected:
            Camera _camera;
            Point _dimensions;
            Rectangle _viewPort;
            std::string _name;
    };
}

#endif //GOAT_ENGINE_SCENE_HPP
