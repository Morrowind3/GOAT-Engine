#include "Application.hpp"

namespace Engine {

    Application::Application(const std::string& title, size_t width, size_t height) : title(title), width(width), height(height) {
        SceneManager sceneManager {};
        _renderingSystem = std::make_unique<RenderingSystem>(sceneManager);
        // TODO: Dynamically load
        auto TestScene = std::map<size_t, GameObject>();
        auto* test = new Scene{TestScene};
        sceneManager.addScene(test);
        sceneManager.setActiveScene(1);
    }

    void Application::run() {
        _renderingSystem->onInit();
        _renderingSystem->onUpdate(1);
    }

    Application::~Application() = default;
}
