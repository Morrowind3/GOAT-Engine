#include "RendererApi.hpp"

using namespace Engine;

void RendererApi::RendererApi::LoadTexture(const std::string& fileName) {
    renderer.LoadTexture(fileName);
}

void RendererApi::RendererApi::LoadFont(const std::string& name, const std::string& path, Uint8 size) {
    renderer.LoadFont(name, path, size);
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