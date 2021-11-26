#include "FpsBehavior.hpp"
#include "Scripts/FpsScript.hpp"
#include "../../Keys.hpp"
#include "Scripts/InputPrintScript.hpp"

FpsBehavior::FpsBehavior(Text& fpsText, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<FpsScript>(fpsText, true)));
    scripts.insert(std::make_pair(Keys::INPUT_DEBUG,std::make_shared<InputPrintScript>(true)));
}
