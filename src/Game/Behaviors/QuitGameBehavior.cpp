#include "QuitGameBehavior.hpp"
#include "Scripts/QuitGameScript.hpp"

QuitGameBehavior::QuitGameBehavior(bool active) : Behavior(active) {
    scripts.emplace_back(std::make_shared<QuitGameScript>(true));
}
