#ifndef GOAT_ENGINE_MAINMENUSCENE_HPP
#define GOAT_ENGINE_MAINMENUSCENE_HPP

#include "../../Engine/API/Scene.hpp"
#include "../GameObjects/UI/Fonts.hpp"
#include <vector>

using namespace Engine;

class MainMenuScene : public Scene {
public:
    MainMenuScene() : Scene("MainMenuScene") {

//        Text text{"Hallo", "", 26, {0, 255, 0}, TOP_CENTER};
//
//        _canvas = std::make_unique<Canvas>(Canvas{
//                                                   Transform{Point{0.0, 0.0}, 0, 0, 1.0, 1.0, FLIP::FLIP_VERTICAL},
//                                                   true,
//                                                   {text} // TODO: Object splicing
//                                           }
//        );

//        gameObjects.emplace_back(_canvas.get());

        gameObjects.push_back(new Fonts());

    }
};

#endif //GOAT_ENGINE_MAINMENUSCENE_HPP
