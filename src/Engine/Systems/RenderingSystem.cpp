#include <iostream>
#include "RenderingSystem.hpp"
#include "../Components/Renderer.hpp"

RenderingSystem::RenderingSystem(const Scene* scene) : System(scene)
{
}

void RenderingSystem::OnInit()
{
    std::cout << "RenderingSystem OnInit" << '\n';
    for (auto &gameObject : _scene->_gameObjects) {
        Renderer::LoadTexture(gameObject.sprite.sprite);
    }
}

void RenderingSystem::OnUpdate()
{
    std::cout << "RenderingSystem OnUpdate" << '\n';
    Renderer::BeginTick();
    for (auto &gameObject : _scene->_gameObjects) {
        Renderer::DrawTexture(gameObject.sprite.sprite, gameObject.transform);
    }
    Renderer::EndTick();
}

void RenderingSystem::OnUpdateDebug()
{
    std::cout << "RenderingSystem OnUpdateDebug" << '\n';
    OnUpdate();
}

void RenderingSystem::OnDestroy()
{
    std::cout << "RenderingSystem OnDestroy" << '\n';
    Renderer::End();
}