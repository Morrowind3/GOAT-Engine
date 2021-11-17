#include "RenderingSystem.hpp"

#include <utility>


using namespace Engine;

RenderingSystem::RenderingSystem(const Scene* scene, std::string& name, std::string& iconPath) :
        System(scene), _api(RendererApi::RendererApi::getInstance(name, iconPath)) {}

void RenderingSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& sprite : gameObject->sprites) {
            _api.LoadTexture(sprite.second.path);
        }
        for (auto &font : gameObject->fonts) {
            _api.LoadFont(font.name, font.path, font.size);
        }
    }
}

void RenderingSystem::OnUpdate(double deltaTime) {
    _api.BeginRenderTick();
    for (auto& gameObject : _scene->gameObjects) {
        if (gameObject->activeSprite) {
            _api.DrawTexture(gameObject->activeSprite->path, gameObject->transform);
        }
    }
    _api.EndRenderTick();
}

void RenderingSystem::OnDestroy() {
    _api.End();
}