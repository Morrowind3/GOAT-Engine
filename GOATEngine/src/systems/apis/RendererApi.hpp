#ifndef GOATENGINE_RENDERERAPI_HPP
#define GOATENGINE_RENDERERAPI_HPP

#include <string>
#include "../../components/Transform.hpp"
#include "../../resources/Texture.hpp"

namespace Engine::RenderApi {
        [[nodiscard]] Texture loadTexture(const std::string& fileName);
        void beginTick();
        void drawTexture(const Texture& texture, const Transform& transform);
        void endTick();
        void end();
    }

#endif //GOATENGINE_RENDERERAPI_HPP
