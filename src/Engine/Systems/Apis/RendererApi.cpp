#include "RendererApi.hpp"

using namespace Engine;

void RendererApi::initialize() {
    renderer.initialize();
}

void RendererApi::setViewPort(Point dimensions) {
    renderer.setViewPort(dimensions);
}

void RendererApi::RendererApi::loadTexture(const std::string& fileName) {
    renderer.loadTexture(fileName);
}

void RendererApi::RendererApi::loadFont(const std::string& fileName) {
    renderer.loadFont(fileName);
}

void RendererApi::RendererApi::beginRenderTick() {
    renderer.beginRenderTick();
}

void RendererApi::RendererApi::drawTexture(const std::string& texture, const std::shared_ptr<Transform>& location) {
    renderer.drawTexture(texture, location);
}

void RendererApi::RendererApi::drawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const std::shared_ptr<Transform>& transform) {
    renderer.drawText(text, size, color, fontName, transform);
}

void RendererApi::RendererApi::endRenderTick() {
    renderer.endRenderTick();
}

void RendererApi::resetForNextScene() {
    renderer.resetForNextScene();
}

void RendererApi::RendererApi::end() {
    renderer.end();
}
