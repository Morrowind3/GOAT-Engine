#include "FpsMeter.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"
#include "../../../Behaviors/Utils/FpsMeterBehavior.hpp"

FpsMeter::FpsMeter(bool active): GameObject(Transform{{0,0}}, active) {
    text.insert(std::make_pair(Keys::FPS, Text{"FPS", "Fonts/Fraps.ttf", 48,
       Color{0,0,0,255},
       Transform{Point{0,0},LAYER::FPS}, // ALWAYS on top!
       false}));
    behaviors.insert(std::make_pair(Keys::FPS, std::make_shared<FpsMeterBehavior>(text.at(Keys::FPS),true)));
}
