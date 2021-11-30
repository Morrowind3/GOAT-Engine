#pragma once

#include "System.hpp"
#include "../Systems/Apis/RendererApi.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor);
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            RendererApi* _api = nullptr;
            std::string& _name, _iconPath, _cursor;
    };
}
