#include "EtappeBehavior.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Utils/Cheats/CheatObjects/PauseScript.hpp"
#include "Scripts/LifeInitScript.hpp"

EtappeBehavior::EtappeBehavior(int startHpAmount, AudioSource& pauseSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<LifeInitScript>(startHpAmount, true)));
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(pauseSound,true)));
}
