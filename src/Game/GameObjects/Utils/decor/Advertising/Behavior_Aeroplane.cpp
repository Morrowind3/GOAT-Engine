#include "Behavior_Aeroplane.hpp"
#include "../../../../Keys.hpp"
#include "Script_AeroplaneFlight.hpp"

Behavior_Aeroplane::Behavior_Aeroplane(Object_Aeroplane& plane, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::AEROPLANE, std::make_shared<Script_AeroplaneFlight>(plane, active)));
}
