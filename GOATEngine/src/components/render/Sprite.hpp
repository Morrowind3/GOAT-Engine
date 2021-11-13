#ifndef GOATENGINE_SPRITE_HPP
#define GOATENGINE_SPRITE_HPP

#include "../../core/Base.hpp"

namespace Engine {
    class Sprite {
        public:
            explicit Sprite(std::string path/*TODO: TypeId, TextureFlip, SortingLayer, OrderInLayer*/);
            [[nodiscard]] const std::string& path() const;
        private:
            std::string _path;
    };
}

#endif //GOATENGINE_SPRITE_HPP
