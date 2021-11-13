#include "Application.hpp"

namespace Engine {

    Application::Application(const std::string& title, size_t width, size_t height) : title(title), width(width), height(height) {

        SceneManager sceneManager {};
        RenderingSystem renderingSystem {sceneManager};

        sceneManager.addScene({});
        sceneManager.setActiveScene(1);

    }

    void Application::run() {

    }
}
