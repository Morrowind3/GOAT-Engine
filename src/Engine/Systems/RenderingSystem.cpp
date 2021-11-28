#include "RenderingSystem.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor):
    _name{name}, _iconPath(iconPath), _cursor(cursor)  {
}

void RenderingSystem::onLaunchEngine() {
    _debug.log("Rendering system launch");
    _api = &RendererApi::RendererApi::getInstance(_name, _iconPath, _cursor);
}

void RenderingSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Rendering system load");
    _api->resetForNextScene();
    _scene = scene;
    for (auto& gameObject: _scene->gameObjects) {
        for (auto& sprite: gameObject->sprites) {
            _api->loadTexture(sprite.second.path);
        }
        for (auto& text: gameObject->text) {
            _api->loadFont(text.second.font);
        }
        for (auto& button: gameObject->buttons) {
            _api->loadFont(button.second.text.font);
            _api->loadTexture(button.second.sprite.path);
        }
    }
}

void RenderingSystem::onFrameTick(double deltaTime) {
    _api->beginRenderTick();
    for (auto& gameObject: activeObjects()) {
        if(!gameObject->transform.visible) continue;
        for (auto& sprite: gameObject->sprites) {
            if (!sprite.second.active) continue;
            std::shared_ptr camAdjustedSprite = std::make_shared<Transform>(
                    _scene->getCamera()->adjustForCamera(gameObject->transform));
            _api->drawTexture(sprite.second.path, camAdjustedSprite);
        }
        for (auto& text: gameObject->text) {
            if (!text.second.active) continue;
            std::shared_ptr   camAdjustedText = std::make_shared<Transform>(
                    _scene->getCamera()->adjustForCamera(text.second.location));
            _api->drawText(text.second.text, text.second.size, text.second.color, text.second.font, camAdjustedText);
        }
        for (auto& button: gameObject->buttons) {
            if (!button.second.active) continue;
            std::shared_ptr btnPointer = std::make_shared<Transform>(
                    _scene->getCamera()->adjustForCamera(gameObject->transform));
            std::shared_ptr txtPointer = std::make_shared<Transform>(
                    _scene->getCamera()->adjustForCamera(button.second.text.location));
            _api->drawTexture(button.second.sprite.path, btnPointer);
            _api->drawText(button.second.text.text, button.second.text.size, button.second.text.color,
                           button.second.text.font, txtPointer);
        }
    }
    _api->endRenderTick();
}

void RenderingSystem::onCloseEngine() {
    _debug.log("Rendering system close");
    _api->end();
}
