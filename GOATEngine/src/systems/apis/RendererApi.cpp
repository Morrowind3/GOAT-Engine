#include "RendererApi.hpp"

#include "implementations/RendererImpl.hpp"

using namespace Engine;

static RendererImpl RENDER_IMPL{};

Texture RenderApi::loadTexture(const std::string &fileName) {
    return RENDER_IMPL.loadTexture(fileName);
}

void RenderApi::beginTick() {
    RENDER_IMPL.beginRenderTick();
}

void RenderApi::drawTexture(const Texture& texture, const Transform& transform) {
    RENDER_IMPL.drawTexture(texture, transform);
}

void RenderApi::endTick() {
    RENDER_IMPL.endRenderTick();
}

void RenderApi::end() {
    RENDER_IMPL.end();
}