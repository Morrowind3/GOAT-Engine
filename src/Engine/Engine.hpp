#pragma once

#include <memory>
#include <vector>

#include "API/Scene.hpp"
#include "SceneManager.hpp"
#include "Systems/System.hpp"

namespace Engine {
    class GoatEngine {
    public:
        explicit GoatEngine();
        void Run();
        SceneManager _sceneManager{};
    private:
        bool _isRunning;
        const std::unique_ptr<std::vector<std::unique_ptr<System>>> _systems;
    };
}
