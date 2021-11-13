#include "RenderingSystem.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(SceneManager& manager):
    System(manager), _textureManager{std::make_unique<TextureManager>()} {
}

void RenderingSystem::onInit()
{
    for (auto &gameObject : _manager.getActiveScene()->getAllGameObjects()) {
        // TODO: ID
        _textureManager->Store(0,RenderApi::loadTexture(gameObject.second.getSprite().path()));
    }
}

void RenderingSystem::onUpdate()
{
    RenderApi::beginTick();
    for (auto &gameObject : _manager.getActiveScene()->getAllGameObjects()) {
        // TODO: ID
        RenderApi::drawTexture(_textureManager->Get(0), Transform{Point{0,0},0,1,1});
    }
    RenderApi::endTick();
}

void RenderingSystem::onDestroy()
{
//    RenderApi::end();
}

