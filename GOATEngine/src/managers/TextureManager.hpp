#ifndef GOATENGINE_TEXTUREMANAGER_HPP
#define GOATENGINE_TEXTUREMANAGER_HPP

#include <map>
#include <memory>
#include "../core/Base.hpp"
#include "../resources/Texture.hpp"

namespace Engine {
    class TextureManager {
        public:
            void Store(TypeId id, const Texture& texture);
            Texture Get(TypeId id);
            void Remove(TypeId id);
        private:
            std::unique_ptr<std::map<TypeId,Texture>> _textures;
    };
}

#endif //GOATENGINE_TEXTUREMANAGER_HPP
