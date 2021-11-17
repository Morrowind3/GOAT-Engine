#include "RendererApi.hpp"

using namespace Engine;

void RendererApi::RendererApi::LoadTexture(const std::string& fileName) {
    renderer.LoadTexture(fileName);
}

void RendererApi::RendererApi::BeginRenderTick() {
    renderer.BeginRenderTick();
}

void RendererApi::RendererApi::DrawTexture(const std::string& texture, const Transform& location) {
    renderer.DrawTexture(texture, location);
}

void RendererApi::RendererApi::EndRenderTick() {
    renderer.EndRenderTick();
}

void RendererApi::RendererApi::End() {
    renderer.End();
}