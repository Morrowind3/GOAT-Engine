#include "RenderingSystem.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor):
    _name{name}, _iconPath(iconPath), _cursor(cursor)  {
}

void RenderingSystem::OnLaunchEngine() {
    _api = &RendererApi::RendererApi::getInstance(_name, _iconPath, _cursor);
}

void RenderingSystem::OnLoadScene(const Scene* scene) {
    _scene = scene;
    for (auto& gameObject: _scene->gameObjects) {
        for (auto& sprite: gameObject->sprites) {
            _api->LoadTexture(sprite.second.path);
        }
        for (auto& text: gameObject->text) {
            _api->LoadFont(text.second.font);
        }
        for (auto& button: gameObject->buttons) {
            _api->LoadFont(button.second.text.font);
        }
    }
}

void RenderingSystem::OnFrameTick(double deltaTime) {
    _api->BeginRenderTick();
    for (auto& gameObject: activeObjects()) {
        for (auto& sprite: gameObject->sprites) {
            if (sprite.second.active) _api->DrawTexture(sprite.second.path, gameObject->transform);
        }
        for (auto& text: gameObject->text) {
            if (text.second.active) _api->DrawText(text.second.text, text.second.size, text.second.color, text.second.font, text.second.location);
        }
        for (auto& button: gameObject->buttons) {
            if (button.second.active) {
                _api->DrawSolid(button.second.backgroundColor, button.second.dimensions);
                _api->DrawText(button.second.text.text, button.second.text.size, button.second.text.color, button.second.text.font, button.second.text.location);
            }
        }
    }
    _api->EndRenderTick();
}

void RenderingSystem::OnCloseEngine() {
    _api->End();
}


