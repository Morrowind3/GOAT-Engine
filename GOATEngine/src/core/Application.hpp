//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_APPLICATION_HPP
#define GOATENGINE_APPLICATION_HPP

#include "Base.hpp"
#include "System.hpp"

#include <string>
#include <vector>

using namespace spic;

namespace spic {
    class SceneManager;

    class Application : public NoCopyNoMove {
    public:
        void run();

    protected:
//        explicit Application(const std::string &title, int32 width, int32 height);
        explicit Application();

        /**
         * @brief Adds a sub-system to the engine runtime
         *
         * @tparam TSystem System to add
         * @throws runtime_exception Cannot add system while application is running
         */
        template<class TSystem, isBase <System, TSystem> = true>
        void addSystem();

        /**
         * @brief Destruct
         * @details Will cleanup the created resources
         */
        ~Application() override;

        /*
         * Scene manager which keeps track of the scene lifecycles
         */
        unique <SceneManager> manager;

    private:
        /*
         * Scene manager is a friend of the application because it has
         * to access the systems for loading a scene.
         */
        friend class SceneManager;
    };
}

#endif //GOATENGINE_APPLICATION_HPP
