#pragma once

#include "API/Scene.hpp"

#include <vector>

namespace Engine {
    class SceneManager {
        public:
            explicit SceneManager(const std::vector<Scene>& scenes);
            [[nodiscard]] const Scene& Current() const;
        private:
            const std::vector<Scene>& _scenes;
    };
}
