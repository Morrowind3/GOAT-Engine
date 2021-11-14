#ifndef GOAT_ENGINE_SCRIPTSYSTEM_HPP
#define GOAT_ENGINE_SCRIPTSYSTEM_HPP

#include "System.hpp"

namespace Engine {
    class ScriptSystem : public System  {
        public:
            explicit ScriptSystem(const Scene* scene);
            void OnInit() override;
            void OnUpdate() override;
            void OnDestroy() override;
    };
}



#endif //GOAT_ENGINE_SCRIPTSYSTEM_HPP
