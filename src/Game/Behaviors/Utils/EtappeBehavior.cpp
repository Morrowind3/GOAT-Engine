#include "EtappeBehavior.hpp"
#include "../../Keys.hpp"
#include "Scripts/PauseScript.hpp"

EtappeBehavior::EtappeBehavior(AudioSource& pauseSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(pauseSound, true)));
}
