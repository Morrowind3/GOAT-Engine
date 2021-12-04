#include "EtappeBehavior.hpp"
#include "../../../Keys.hpp"
#include "../../Utils/Cheats/CheatsLibrary/PauseScript.hpp"
#include "LifeInitScript.hpp"

EtappeBehavior::EtappeBehavior(int startHpAmount, AudioSource& pauseSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<LifeInitScript>(startHpAmount, true)));
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(pauseSound,true)));
}
