#include "Text.hpp"

using namespace Engine;

Text::Text(std::string text, const std::string& font, int size, Color color, Alignment alignment) :
        text(std::move(text)), font(TTF_OpenFont(font.c_str(), size)), color(color), UIObject(0, 0, alignment,
                                                                                              nullptr) {}
//TTF_RenderText_Blended(this->font, "", this->color)