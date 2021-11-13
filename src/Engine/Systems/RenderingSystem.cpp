#include "RenderingSystem.hpp"
#include "../Systems/Apis/RendererApi.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(const Scene* scene) : System(scene) {
}

void RenderingSystem::OnInit()
{
    for (auto &gameObject : _scene->gameObjects) {
        RendererApi::LoadTexture(gameObject.sprite.path);
    }
}

void RenderingSystem::OnUpdate()
{
    RendererApi::BeginRenderTick();
    for (auto &gameObject : _scene->gameObjects) {
        RendererApi::DrawTexture(gameObject.sprite.path, gameObject.transform);
    }
    RendererApi::EndRenderTick();
}

void RenderingSystem::OnDestroy()
{
    RendererApi::End();
}