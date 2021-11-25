#include "FpsDisplay.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/FpsBehavior.hpp"

FpsDisplay::FpsDisplay(bool active) : GameObject(Transform{Point{0,0}}, active) {
    text.insert(std::make_pair(Keys::FPS,
       Text{"FPS", "Fonts/Fraps.ttf", 48,
            Color{0,0,0,255},
            Transform{Point{0,0},LAYER::UI},
            true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<FpsBehavior>(text.at(Keys::FPS), true)));
}
