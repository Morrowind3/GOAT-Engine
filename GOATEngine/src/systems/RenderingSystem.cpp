#include "RenderingSystem.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(SceneManager& manager):
    System(manager), _textureManager{std::make_unique<TextureManager>()} {
}

void RenderingSystem::onInit()
{
//    for (auto &gameObject : manager->_gameObjects) {
//        RenderApi::loadTexture(gameObject.sprite.sprite);
//    }
}

void RenderingSystem::onUpdate()
{
//    RenderApi::beginTick();
//    for (auto &gameObject : _scene->_gameObjects) {
//        RenderApi::drawTexture(gameObject.sprite.sprite, gameObject.transform);
//    }
//    RenderApi::endTick();
}

void RenderingSystem::onDestroy()
{
//    RenderApi::end();
}

