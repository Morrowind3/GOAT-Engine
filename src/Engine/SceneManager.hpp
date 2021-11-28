#pragma once

#include "API/Scene.hpp"

#include <map>
#include <string>

namespace Engine {
    class SceneManager {
        public:
            [[nodiscard]] std::shared_ptr<Scene> currentScene() const;
            virtual void changeCurrentScene(const std::string& name) = 0;
        protected:
            std::shared_ptr<Scene> _currentScene;
    };
}
