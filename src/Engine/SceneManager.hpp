#pragma once

#include "API/Scene.hpp"

#include <vector>

class SceneManager {
    public:
        explicit SceneManager(const std::vector<Scene>& scenes);
        const Scene& Current() const;
    private:
        const std::vector<Scene>& _scenes;
};