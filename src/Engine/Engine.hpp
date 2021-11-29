#ifndef GOAT_ENGINE_ENGINE_HPP
#define GOAT_ENGINE_ENGINE_HPP

#include <memory>
#include <vector>
#include <string>

#include "API/Scene.hpp"
#include "SceneManager.hpp"
#include "Systems/System.hpp"
#include "Utilities/Input.hpp"
#include "Utilities/Clock.hpp"
#include "Utilities/EngineCalls.hpp"

namespace Engine {
    class GoatEngine {
        public:
            explicit GoatEngine(SceneManager& sceneManager, std::string& name, std::string& iconPath, std::string& cursor,
                                unsigned int maxFps);
            void run();
        private:
            SceneManager& _sceneManager;
            std::string& _name;
            std::string& _iconPath;
            bool _isRunning = false;
            const std::unique_ptr<std::vector<std::unique_ptr<System>>> _systems =
                    std::make_unique<std::vector<std::unique_ptr<System>>>();
            std::string& _cursor;
            // Utilities
            Clock _clock;
            Debug& _debug = Debug::getInstance();
            Input& _input = Input::getInstance();
            EngineCalls& _engineCalls = EngineCalls::getInstance();
    };
}

#endif //GOAT_ENGINE_ENGINE_HPP
