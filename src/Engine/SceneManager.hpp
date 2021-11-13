#pragma once

#include "API/Scene.hpp"

#include <map>
#include <string>

namespace Engine {
    class SceneManager {
    public:
        Scene* CurrentScene() const;

        void ChangeCurrentScene(std::string& name);

        void AddScene(Scene& scene);

        Scene* GetScene(std::string& name) const;

    private:
        Scene* _currentScene = nullptr;
        std::unique_ptr<std::map<std::string, std::unique_ptr<Scene>>> _scenes = std::make_unique<std::map<std::string, std::unique_ptr<Scene>>>();
    };
}
