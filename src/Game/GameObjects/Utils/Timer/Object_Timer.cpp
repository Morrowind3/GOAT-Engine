#include "Object_Timer.hpp"
#include "../../../Keys.hpp"
#include "Behavior_Timer.hpp"
#include "../../../Layers.hpp"

Object_Timer::Object_Timer(bool active) : GameObject(Transform{Point{650,10}}, active){
    text.insert(std::make_pair(Keys::TIMER, Text{"00:00", "Fonts/Symtext.ttf", 48,
                                               Color{0,0,0,255},
                                               Transform{transform.position,LAYER::UI, 1},
                                               true}));
    behaviors.insert(std::make_pair(Keys::TIMER, std::make_shared<Behavior_Timer>(text.at(Keys::TIMER), true)));
}
