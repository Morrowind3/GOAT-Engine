#include "RenderingSystem.hpp"

using namespace Engine;

RenderingSystem::RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor):
    _name{name}, _iconPath(iconPath), _cursor(cursor)  {
}

void RenderingSystem::onLaunchEngine() {
    _debug.log("Rendering system launch");
    _api = &RendererApi::getInstance(_name, _iconPath, _cursor);
}

void RenderingSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Rendering system load");
    _animatorHelper.resetForNextScene();
    _api->resetForNextScene();
    _scene = scene;
    _api->setViewPort(_scene->getViewPort().widthHeightPoint());
    for (auto& gameObject: _scene->gameObjects) {
        loadSpritesData(*gameObject);
        loadTextData(*gameObject);
        loadButtonsData(*gameObject);
    }
}

void RenderingSystem::onFrameTick(const double deltaTime) {
    _api->beginRenderTick();
    _scene->getCamera()->interpolateToNextWaypoint();
    for (auto& gameObject: activeObjects()) {
        handleAnimators(*gameObject,deltaTime);
        if(!gameObject->transform.visible) continue;
        drawSprites(*gameObject);
        drawText(*gameObject);
        drawButtons(*gameObject);
    }
    _api->endRenderTick();
}

void RenderingSystem::onCloseEngine() {
    _debug.log("Rendering system close");
    _api->end();
}

// Load scene helper methods

void RenderingSystem::loadSpritesData(GameObject& gameObject) {
    for (auto& sprite: gameObject.sprites) {
        _api->loadTexture(sprite.second.path);
    }
}

void RenderingSystem::loadTextData(GameObject& gameObject) {
    for (auto& text: gameObject.text) {
        _api->loadFont(text.second.font);
    }
}

void RenderingSystem::loadButtonsData(GameObject& gameObject) {
    for (auto& button: gameObject.buttons) {
        _api->loadFont(button.second.text.font);
        _api->loadTexture(button.second.sprite.path);
    }
}

// Frame tick helper methods

void RenderingSystem::handleAnimators(GameObject& gameObject, const double deltaTime) {
    for (auto& animator: gameObject.animators) {
        if (!animator.second.active) continue;
        _animatorHelper.handleAnimator(animator.second,deltaTime);
    }
}

void RenderingSystem::drawSprites(GameObject& gameObject) {
    for (auto& sprite: gameObject.sprites) {
        if (!sprite.second.active) continue;
        std::shared_ptr camAdjustedSprite = std::make_shared<Transform>(
                _scene->getCamera()->adjustForCamera(gameObject.transform));
        _api->drawTexture(sprite.second.path, camAdjustedSprite);
    }
}

void RenderingSystem::drawText(GameObject& gameObject) {
    for (auto& text: gameObject.text) {
        if (!text.second.active) continue;
        std::shared_ptr camAdjustedText = std::make_shared<Transform>(
                _scene->getCamera()->adjustForCamera(text.second.location));
        _api->drawText(text.second, camAdjustedText);
    }
}

void RenderingSystem::drawButtons(GameObject& gameObject) {
    for (auto& button: gameObject.buttons) {
        if (!button.second.active) continue;
        std::shared_ptr btnPointer = std::make_shared<Transform>(
                _scene->getCamera()->adjustForCamera(gameObject.transform));
        std::shared_ptr txtPointer = std::make_shared<Transform>(
                _scene->getCamera()->adjustForCamera(button.second.text.location));
        _api->drawTexture(button.second.sprite.path, btnPointer);
        _api->drawText(button.second.text, txtPointer);
    }
}
