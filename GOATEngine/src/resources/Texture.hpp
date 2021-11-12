#ifndef GOATENGINE_TEXTURE_HPP
#define GOATENGINE_TEXTURE_HPP

#include <memory>
#include "SDL.h"

class Texture {
    public:
        explicit Texture(SDL_Texture* texture);
        [[nodiscard]] SDL_Texture* texture() const;
        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;
    private:
        SDL_Texture* _texture;
        int _width, _height;
};


#endif //GOATENGINE_TEXTURE_HPP
