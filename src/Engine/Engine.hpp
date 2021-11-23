#pragma once

#include <memory>
#include <vector>
#include <string>

#include "API/Scene.hpp"
#include "SceneManager.hpp"
#include "Systems/System.hpp"

namespace Engine {
    class GoatEngine {
    public:
        explicit GoatEngine(std::string& name, std::string& iconPath);
        void Run();
        SceneManager sceneManager{};
    private:
        bool _isRunning;
        const std::unique_ptr<std::vector<std::unique_ptr<System>>> _systems;
        std::string& _name;
        std::string& _iconPath;
    };
}
