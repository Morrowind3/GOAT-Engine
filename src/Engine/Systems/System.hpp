#ifndef GOAT_ENGINE_SYSTEM_HPP
#define GOAT_ENGINE_SYSTEM_HPP

#include "../Utilities/Debug.hpp"
#include "../API/Scene.hpp"

namespace Engine {
    class System {
        public:
            System() = default;
            virtual void onLaunchEngine() = 0;                          // Called when the program starts
            virtual void onLoadScene(std::shared_ptr<Scene> scene) = 0; // Called when loading or switching scene
            virtual void onFrameTick(double deltaTime) = 0;             // Called when a frame gets processed by the system
            virtual void onCloseEngine() = 0;                           // Called when the program ends
        protected:
            std::shared_ptr<Scene> _scene;
            Debug& _debug = Debug::getInstance();
            [[nodiscard]] std::vector<std::shared_ptr<GameObject>> activeObjects() const;
    };
}

#endif //GOAT_ENGINE_SYSTEM_HPP
