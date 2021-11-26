#include "FpsBehavior.hpp"
#include "Scripts/FpsScript.hpp"
#include "../../Keys.hpp"

FpsBehavior::FpsBehavior(Text& fpsText, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<FpsScript>(fpsText, true)));
}
