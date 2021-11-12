//
// Created by Stijn van Loon on 12-11-2021.
//

#include "RendererApi.hpp"

#include "implementations/RendererImpl.hpp"

static RendererImpl RENDER_IMPL{};

void RendererApi::loadTexture(const std::string &fileName) {
    RENDER_IMPL.loadTexture(fileName);
}

void RendererApi::beginTick() {
    RENDER_IMPL.beginRenderTick();
}

//void RendererApi::drawTexture(const std::string &spriteName, const Transform &transform) {
//    RENDER_IMPL.DrawTexture(spriteName, transform);
//}

void RendererApi::endTick() {
    RENDER_IMPL.endRenderTick();
}

void RendererApi::end() {
    RENDER_IMPL.end();
}