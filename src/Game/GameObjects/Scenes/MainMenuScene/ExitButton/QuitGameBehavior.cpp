#include "QuitGameBehavior.hpp"
#include "QuitGameScript.hpp"
#include "../../../../Keys.hpp"

QuitGameBehavior::QuitGameBehavior(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<QuitGameScript>(true)));
}