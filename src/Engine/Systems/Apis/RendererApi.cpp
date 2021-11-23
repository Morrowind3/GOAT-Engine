#include "RendererApi.hpp"
#include "../../API/Camera.hpp"

using namespace Engine;

void RendererApi::RendererApi::LoadTexture(const std::string& fileName) {
    renderer.LoadTexture(fileName);
}

void RendererApi::RendererApi::LoadFont(const std::string& fileName) {
    renderer.LoadFont(fileName);
}

void RendererApi::RendererApi::BeginRenderTick() {
    renderer.BeginRenderTick();
}

void RendererApi::RendererApi::DrawTexture(const std::string& texture, const Transform& location) {
    renderer.DrawTexture(texture, location);
}

void RendererApi::RendererApi::DrawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const Transform& transform) {
    renderer.DrawText(text,size,color,fontName,transform);
}

void RendererApi::RendererApi::EndRenderTick() {
    renderer.EndRenderTick();
}

void RendererApi::RendererApi::End() {
    renderer.End();
}
