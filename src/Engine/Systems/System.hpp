#ifndef GOAT_ENGINE_SYSTEM_HPP
#define GOAT_ENGINE_SYSTEM_HPP

#include "../API/Scene.hpp"

namespace Engine {
    class System {
        public:
            explicit System(const Scene* scene);
            virtual void OnInit() = 0;
            virtual void OnUpdate(double deltaTime) = 0;
            virtual void OnDestroy() = 0;
        protected:
            const Scene* _scene;
            [[nodiscard]] std::vector<std::shared_ptr<GameObject>> activeObjects() const;
    };
}

#endif //GOAT_ENGINE_SYSTEM_HPP
