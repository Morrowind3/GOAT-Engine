#ifndef GOAT_ENGINE_FONTS_HPP
#define GOAT_ENGINE_FONTS_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/UI/Font.hpp"

using namespace Engine;

class Fonts : public GameObject {
public:
    Fonts() : GameObject(Transform{Point{0,0},1,0,0,0}, true) {
        std::string name{"default"};
        std::string path{"Fonts/Kenney_Thick.ttf"};

        this->fonts.emplace_back(name, path, 25, true);
    };
};


#endif //GOAT_ENGINE_FONTS_HPP
