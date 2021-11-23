#ifndef GOAT_ENGINE_SYSTEM_HPP
#define GOAT_ENGINE_SYSTEM_HPP

#include "../API/Scene.hpp"

namespace Engine {
    class System {
        public:
            System() = default;
            virtual void OnLaunchEngine() = 0;                // Called when the program starts
            virtual void OnLoadScene(const Scene* scene) = 0; // Called when loading or switching scene
            virtual void OnFrameTick(double deltaTime) = 0;   // Called when a frame gets processed by the systems
            virtual void OnCloseEngine() = 0;                 // Called when the program ends
        protected:
            const Scene* _scene = nullptr;
            [[nodiscard]] std::vector<std::shared_ptr<GameObject>> activeObjects() const;
    };
}

#endif //GOAT_ENGINE_SYSTEM_HPP
