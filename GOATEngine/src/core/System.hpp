#ifndef GOATENGINE_SYSTEM_HPP
#define GOATENGINE_SYSTEM_HPP

#include "Base.hpp"
#include "../components/Scene.hpp"

#include <utility>

namespace Engine {
    class SceneManager;

    class System {
    public:
        explicit System(SceneManager& manager) : _manager(manager) { }

        /**
         * @brief On scene load is called when the system must load the scene resources
         *
         * @param scene Scene to load
         */
        virtual void onSceneLoad(Scene& scene) = 0;

        /**
         * @brief On update is called for every frame update
         *
         * @param deltaTime Delta time between update
         */
        virtual void onUpdate(double deltaTime) = 0;

        /**
         * @brief On scene unload is called when the system must unload the scene resources
         *
         * @param scene Scene to unload
         */
        virtual void onSceneUnload(Scene& scene) = 0;

        virtual ~System() = default;
    protected:
        SceneManager& _manager;
    };
}


#endif //GOATENGINE_SYSTEM_HPP
