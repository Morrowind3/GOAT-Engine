//
// Created by Stijn van Loon on 17-11-2021.
//

#include "Font.hpp"

#include <utility>

using namespace Engine;

Font::Font(std::string name, std::string path, Uint8 size, bool active) :
        GameComponent(active), name(std::move(name)), path(std::move(path)), size(size) {}