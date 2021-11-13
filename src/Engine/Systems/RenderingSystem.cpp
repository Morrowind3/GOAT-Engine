#include <iostream>
#include "RenderingSystem.hpp"
#include "../Systems/Apis/RendererApi.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(const Scene* scene) : System(scene)
{
}

void RenderingSystem::OnInit()
{
    std::cout << "RenderingSystem OnInit" << '\n';
    for (auto &gameObject : _scene->gameObjects) {
        RendererApi::LoadTexture(gameObject.sprite.path);
    }
}

void RenderingSystem::OnUpdate()
{
    std::cout << "RenderingSystem OnUpdate" << '\n';
    RendererApi::BeginRenderTick();
    for (auto &gameObject : _scene->gameObjects) {
        RendererApi::DrawTexture(gameObject.sprite.path, gameObject.transform);
    }
    RendererApi::EndRenderTick();
}

void RenderingSystem::OnUpdateDebug()
{
    std::cout << "RenderingSystem OnUpdateDebug" << '\n';
    OnUpdate();
}

void RenderingSystem::OnDestroy()
{
    std::cout << "RenderingSystem OnDestroy" << '\n';
    RendererApi::End();
}