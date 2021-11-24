#ifndef GOAT_ENGINE_SCRIPTSYSTEM_HPP
#define GOAT_ENGINE_SCRIPTSYSTEM_HPP

#include "System.hpp"

namespace Engine {
    class ScriptSystem : public System  {
        public:
            ScriptSystem() = default;
            void OnLaunchEngine() override;
            void OnLoadScene(std::shared_ptr<Scene> scene) override;
            void OnFrameTick(double deltaTime) override;
            void OnCloseEngine() override;
    };
}



#endif //GOAT_ENGINE_SCRIPTSYSTEM_HPP
