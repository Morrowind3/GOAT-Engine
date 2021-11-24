#ifndef GOAT_ENGINE_SYSTEM_HPP
#define GOAT_ENGINE_SYSTEM_HPP

#include "../API/Scene.hpp"

namespace Engine {
    class System {
        public:
            System() = default;
            virtual void OnLaunchEngine() = 0;                          // Called when the program starts
            virtual void OnLoadScene(std::shared_ptr<Scene> scene) = 0; // Called when loading or switching scene
            virtual void OnFrameTick(double deltaTime) = 0;             // Called when a frame gets processed by the system
            virtual void OnCloseEngine() = 0;                           // Called when the program ends
        protected:
            std::shared_ptr<Scene> _scene;
            [[nodiscard]] std::vector<std::shared_ptr<GameObject>> activeObjects() const;
    };
}

#endif //GOAT_ENGINE_SYSTEM_HPP
