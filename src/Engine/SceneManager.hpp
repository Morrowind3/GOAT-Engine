#pragma once

#include "API/Scene.hpp"

#include <map>
#include <string>

namespace Engine {
    class SceneManager {
        public:
            [[nodiscard]] std::shared_ptr<Scene> CurrentScene() const;
            virtual void ChangeCurrentScene(const std::string& name) = 0;
        protected:
            std::shared_ptr<Scene> _currentScene;
    };
}
