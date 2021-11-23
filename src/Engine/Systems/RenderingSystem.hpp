#pragma once

#include "System.hpp"
#include "../Systems/Apis/RendererApi.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            RenderingSystem(std::string& name, std::string& iconPath);
            void OnLaunchEngine() override;
            void OnLoadScene(const Scene* scene) override;
            void OnFrameTick(double deltaTime) override;
            void OnCloseEngine() override;
        private:
            RendererApi* _api = nullptr;
            std::string& _name, _iconPath;
    };
}
