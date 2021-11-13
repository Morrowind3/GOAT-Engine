#pragma once

#include <string>
#include "../API/GameObjects/Transform.hpp"

namespace Renderer {
    void LoadTexture(const std::string& fileName);
    void BeginTick();
    void DrawTexture(const std::string& spriteName, const Transform& transform);
    void EndTick();
    void End();
}