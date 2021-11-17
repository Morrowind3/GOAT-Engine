//
// Created by Stijn van Loon on 17-11-2021.
//

#ifndef GOAT_ENGINE_FONTMANAGER_HPP
#define GOAT_ENGINE_FONTMANAGER_HPP

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <map>
#include <memory>

namespace Engine {
    class FontManager {
    public:
        FontManager();

        void store(const std::string& name, const std::string& path, Uint8 size);

        [[nodiscard]] const TTF_Font* get(const std::string& name) const;

        void remove(const std::string& name);

    private:
        std::unique_ptr<std::map<std::string, TTF_Font*>> _fonts;
    };
}

#endif //GOAT_ENGINE_FONTMANAGER_HPP
