#include "Renderer.hpp"

#include "Libraries/RendererHandler.hpp"

static RendererHandler RENDER_HANDLER {};

void Renderer::LoadTexture(const std::string& fileName)
{
    RENDER_HANDLER.LoadTexture(fileName);
}

void Renderer::BeginTick()
{
    RENDER_HANDLER.BeginRenderTick();
}

void Renderer::DrawTexture(const std::string& spriteName, const Transform& transform)
{
    RENDER_HANDLER.DrawTexture(spriteName, transform);
}

void Renderer::EndTick()
{
    RENDER_HANDLER.EndRenderTick();
}

void Renderer::End()
{
    RENDER_HANDLER.End();
}