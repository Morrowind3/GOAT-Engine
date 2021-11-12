//
// Created by Stijn van Loon on 12-11-2021.
//

#include <iostream>
#include "RenderingSystem.hpp"

//RenderingSystem::RenderingSystem(const Scene* scene) : System(scene)
//{
//}

void RenderingSystem::onInit()
{
    std::cout << "RenderingSystem OnInit" << '\n';
//    for (auto &gameObject : _scene->_gameObjects) {
//        RendererApi::loadTexture(gameObject.sprite.sprite);
//    }
}

void RenderingSystem::onUpdate()
{
    std::cout << "RenderingSystem OnUpdate" << '\n';
    RenderApi::beginTick();
//    for (auto &gameObject : _scene->_gameObjects) {
//        RendererApi::drawTexture(gameObject.sprite.sprite, gameObject.transform);
//    }
    RenderApi::endTick();
}

void RenderingSystem::onUpdateDebug()
{
    std::cout << "RenderingSystem OnUpdateDebug" << '\n';
    onUpdate();
}

void RenderingSystem::onDestroy()
{
    std::cout << "RenderingSystem OnDestroy" << '\n';
    RenderApi::end();
}
