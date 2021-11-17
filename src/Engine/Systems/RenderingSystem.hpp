#pragma once

#include "System.hpp"
#include "../Systems/Apis/RendererApi.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            explicit RenderingSystem(const Scene* scene, std::string& name, std::string& iconPath);
            void OnInit() override;
            void OnUpdate(double deltaTime) override;
            void OnDestroy() override;

    private:
        RendererApi::RendererApi& _api;
    };
}
