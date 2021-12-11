//
// Created by Morrowind3 on 11/12/2021.
//

#include "AeroplaneBehavior.hpp"
#include "../../../../Keys.hpp"
#include "AeroplaneFlightScript.hpp"

AeroplaneBehavior::AeroplaneBehavior(Aeroplane& plane, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::AEROPLANE, std::make_shared<AeroplaneFlightScript>(plane, active)));
}
