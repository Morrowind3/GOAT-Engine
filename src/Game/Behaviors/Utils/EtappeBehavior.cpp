#include "EtappeBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/Cheats/PauseScript.hpp"
#include "Scripts/LifeInitScript.hpp"

EtappeBehavior::EtappeBehavior(int startHpAmount, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<LifeInitScript>(startHpAmount, true)));
}
