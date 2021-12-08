#ifndef GOAT_ENGINE_SCRIPTSYSTEM_HPP
#define GOAT_ENGINE_SCRIPTSYSTEM_HPP

#include "System.hpp"
#include "Apis/PhysicsApi.hpp"
#include "../Utilities/Input.hpp"

namespace Engine {
    class ScriptSystem : public System  {
        public:
            ScriptSystem() = default;
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            // API
            PhysicsApi& _physics = PhysicsApi::getInstance();
            // Utilities
            Input& _input = Input::getInstance();
            // Helper methods (needs a reference to all active objects, so they only need to get queried from the scene once per tick)
            static void runOnStarts(std::vector<std::shared_ptr<GameObject>>& activeObjects);
            static void runOnUpdates(std::vector<std::shared_ptr<GameObject>>& activeObjects, double deltaTime);
            [[nodiscard]] bool buttonPressed(const Rectangle& buttonDimensions);
            void runPressedButtons(std::vector<std::shared_ptr<GameObject>>& activeObjects);
            static void runOnDestroys(std::vector<std::shared_ptr<GameObject>>& activeObjects);
    };
}



#endif //GOAT_ENGINE_SCRIPTSYSTEM_HPP
