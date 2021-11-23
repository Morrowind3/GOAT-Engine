#include "RenderingSystem.hpp"
#include <fstream>

using namespace Engine;

RenderingSystem::RenderingSystem(const Scene* scene, std::string& name, std::string& iconPath) :
        System(scene), _api(RendererApi::RendererApi::getInstance(name, iconPath)) {}

void RenderingSystem::OnInit() {
    for (auto& gameObject: _scene->gameObjects) {
        for (auto& sprite: gameObject->sprites) {
            _api.LoadTexture(sprite.second.path);
        }
        for (auto& text: gameObject->text) {
            _api.LoadFont(text.second.font);
        }
        for (auto& button: gameObject->buttons) {
            _api.LoadFont(button.second.text.font);
        }
    }
}

void RenderingSystem::OnUpdate(double deltaTime) {
    _api.BeginRenderTick();
    for (auto& gameObject: activeObjects()) {
        for (auto& sprite: gameObject->sprites) {
            if (sprite.second.active) _api.DrawTexture(sprite.second.path, gameObject->transform);
        }
        for (auto& text: gameObject->text) {
            if (text.second.active) _api.DrawText(text.second.text, text.second.size, text.second.color, text.second.font, text.second.location);
        }
        // TODO: Button rendering
        for (auto& button: gameObject->buttons) {
            if (button.second.active) _api.DrawText(button.second.text.text, button.second.text.size, button.second.text.color, button.second.text.font, button.second.text.location);
        }
    }
    _api.EndRenderTick();
}

void RenderingSystem::OnDestroy() {
    _api.End();
}