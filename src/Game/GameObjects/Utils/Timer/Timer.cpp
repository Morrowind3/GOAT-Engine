#include "Timer.hpp"
#include "../../../Keys.hpp"
#include "TimerBehavior.hpp"
#include "../../../Layers.hpp"

Timer::Timer(bool active) : GameObject(Transform{Point{650,10}}, active){
    text.insert(std::make_pair(Keys::TIMER, Text{"00:00", "Fonts/Symtext.ttf", 48,
                                               Color{0,0,0,255},
                                               Transform{transform.position,LAYER::UI, 1},
                                               true}));
    behaviors.insert(std::make_pair(Keys::TIMER, std::make_shared<TimerBehavior>(text.at(Keys::TIMER), true)));
}
