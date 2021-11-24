#include "FpsBehavior.hpp"
#include "Scripts/FpsScript.hpp"

FpsBehavior::FpsBehavior(Text& fpsText, bool active): Behavior(active) {
    scripts.emplace_back(std::make_shared<FpsScript>(fpsText, true));
}
