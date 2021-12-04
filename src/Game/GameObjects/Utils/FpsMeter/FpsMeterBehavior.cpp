#include "FpsMeterBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/Cheats/FpsScript.hpp"

FpsMeterBehavior::FpsMeterBehavior(Text& fpsText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<FpsScript>(fpsText, true)));
}
