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
    }
}

void RenderingSystem::OnUpdate(double deltaTime) {
    _api.BeginRenderTick();
    for (auto& gameObject: activeObjects()) {
        Transform cameraAdjustedTransform = _scene->GetCamera()->AdjustForCamera(gameObject->transform);
        for (auto& sprite: gameObject->sprites) {
            if (sprite.second.active) _api.DrawTexture(sprite.second.path, cameraAdjustedTransform);
        }
        for (auto& text: gameObject->text) {
            if (!text.second.active) continue;
            cameraAdjustedTransform = _scene->GetCamera()->AdjustForCamera(text.second.location);
            _api.DrawText(text.second.text, text.second.size, text.second.color, text.second.font,
                          cameraAdjustedTransform);
        }
    }
    _api.EndRenderTick();
}

void RenderingSystem::OnDestroy() {
    _api.End();
}