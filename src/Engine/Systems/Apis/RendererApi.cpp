#include "RendererApi.hpp"
#include "Implementations/RendererImpl.hpp"

using namespace Engine;
using namespace Engine::RendererApi;

static RendererImpl RENDERER_IMPL{};

void RendererApi::LoadTexture(const std::string& fileName) {
    RENDERER_IMPL.LoadTexture(fileName);
}

void RendererApi::BeginRenderTick() {
    RENDERER_IMPL.BeginRenderTick();
}

void RendererApi::DrawTexture(const std::string& texture, const Transform& location) {
    RENDERER_IMPL.DrawTexture(texture, location);
}

void RendererApi::EndRenderTick() {
    RENDERER_IMPL.EndRenderTick();
}

void RendererApi::End() {
    RENDERER_IMPL.End();
}