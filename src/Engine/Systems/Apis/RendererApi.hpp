#ifndef GOAT_ENGINE_RENDERERAPI_HPP
#define GOAT_ENGINE_RENDERERAPI_HPP

#include <string>
#include "../../API/GameObjects/Transform.hpp"

namespace Engine::RendererApi {
    void LoadTexture(const std::string &fileName);
    void BeginRenderTick();
    void DrawTexture(const std::string& texture, const Transform& location);
    void EndRenderTick();
    void End();
}

#endif //GOAT_ENGINE_RENDERERAPI_HPP
