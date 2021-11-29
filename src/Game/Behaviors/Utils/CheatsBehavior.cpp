#include "CheatsBehavior.hpp"
#include "Scripts/Cheats/PauseScript.hpp."
#include "Scripts/Cheats/FpsScript.hpp"
#include "Scripts/CheatsScript.hpp"
#include "../../Keys.hpp"
#include "Scripts/Cheats/SpeedScript.hpp"

CheatsBehavior::CheatsBehavior(std::map<std::string, Text>& textObjects, AudioSource& pauseSound,
                               AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSpeedSound,
                               AudioSource& errorSound, bool active): Behavior(active) {

    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(pauseSound,true))); // TODO: Is pausing really a cheat?
    scripts.insert(std::make_pair(Keys::SPEED, std::make_shared<SpeedScript>(speedUpSound,slowDownSound,resetSpeedSound,errorSound,true)));
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<FpsScript>(textObjects.at(Keys::FPS), true)));
    scripts.insert(std::make_pair(Keys::CHEATS, std::make_shared<CheatsScript>(textObjects, true)));
}
