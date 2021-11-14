#pragma once

#include "System.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            explicit RenderingSystem(const Scene* scene);
            void OnInit() override;
            void OnUpdate(double deltaTime) override;
            void OnDestroy() override;
    };
}
