//
// Created by Morrowind3 on 06/12/2021.
//

#include "TrashCounter.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"
#include "../Timer/TimerBehavior.hpp"
#include "TrashCounterBehavior.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

TrashCounter::TrashCounter(bool active) :  GameObject(Transform{{1640,12}, LAYER::UI, 1,2,2}, active) {
    sprites.insert(std::make_pair(Keys::TRASH, Sprite{"Sprites/ui/rest/trash_bin.png",true}));

    text.insert(std::make_pair(Keys::TRASH, Text{"00", "Fonts/Symtext.ttf", 48,
                                               Color{0,0,0,255},
                                               Transform{Point{1710,10},LAYER::UI},
                                               true}));
    behaviors.insert(std::make_pair(Keys::TRASH, std::make_shared<TrashCounterBehavior>(text.at(Keys::TRASH), true)));
}
