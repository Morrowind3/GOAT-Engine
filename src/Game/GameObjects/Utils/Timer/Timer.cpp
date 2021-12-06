#include "Timer.hpp"
#include "../../../Keys.hpp"
#include "TimerBehavior.hpp"
#include "../../../Layers.hpp"

Timer::Timer(Transform transform, bool active) : GameObject(transform, active){
    text.insert(std::make_pair(Keys::TIMER, Text{"00:00", "Fonts/Symtext.ttf", 48,
                                               Color{0,0,0,255},
                                               Transform{Point{900,10},LAYER::UI, 1},
                                               true}));
    behaviors.insert(std::make_pair(Keys::TIMER, std::make_shared<TimerBehavior>(text.at(Keys::TIMER), true)));
}
