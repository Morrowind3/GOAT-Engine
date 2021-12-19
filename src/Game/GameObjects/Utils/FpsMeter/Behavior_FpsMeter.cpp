#include "Behavior_FpsMeter.hpp"
#include "../../../Keys.hpp"
#include "Script_FpsMeter.hpp"

Behavior_FpsMeter::Behavior_FpsMeter(Text& fpsText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<Script_FpsMeter>(fpsText, true)));
}
