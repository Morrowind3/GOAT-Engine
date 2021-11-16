#include "RenderingSystem.hpp"
#include "../Systems/Apis/RendererApi.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(const Scene* scene) : System(scene) {
}

void RenderingSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& sprite : gameObject->sprites) {
            RendererApi::LoadTexture(sprite.second.path);
        }
    }
}

void RenderingSystem::OnUpdate(double deltaTime) {
    RendererApi::BeginRenderTick();
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& sprite : gameObject->sprites) {
            RendererApi::DrawTexture(sprite.second.path, gameObject->transform);
        }
    }
    RendererApi::EndRenderTick();
}

void RenderingSystem::OnDestroy() {
    RendererApi::End();
}