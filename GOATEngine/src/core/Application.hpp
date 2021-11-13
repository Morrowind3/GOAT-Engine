//
// Created by Stijn van Loon on 12-11-2021.
//

#ifndef GOATENGINE_APPLICATION_HPP
#define GOATENGINE_APPLICATION_HPP

#include "Base.hpp"
#include "System.hpp"
#include "../systems/RenderingSystem.hpp"

#include <string>
#include <vector>

namespace Engine {
    class SceneManager;

    class Application : public NoCopyNoMove {
    public:
        void run();

    protected:
        explicit Application(const std::string &title, size_t width, size_t height);

//        void addSystem(System system);
//
//        ~Application() override;

        unique <SceneManager> manager;

    private:
        std::string title;
        size_t width;
        size_t height;

    };
}

#endif //GOATENGINE_APPLICATION_HPP
