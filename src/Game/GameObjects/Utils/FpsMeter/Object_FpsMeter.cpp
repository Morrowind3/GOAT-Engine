#include "Object_FpsMeter.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"
#include "Behavior_FpsMeter.hpp"

Object_FpsMeter::Object_FpsMeter(bool active): GameObject(Transform{{0,0}}, active) {
    text.insert(std::make_pair(Keys::FPS, Text{"FPS", "Fonts/Fraps.ttf", 48,
       Color{0,0,0,255},
       Transform{Point{0,0},LAYER::UI, 0xffffffff},
       false}));
    behaviors.insert(std::make_pair(Keys::FPS, std::make_shared<Behavior_FpsMeter>(text.at(Keys::FPS),true)));
}
