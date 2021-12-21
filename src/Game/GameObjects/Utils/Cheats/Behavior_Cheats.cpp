#include "Behavior_Cheats.hpp"
#include "Script_Cheats.hpp"
#include "../../../Keys.hpp"
#include "CheatsLibrary/Script_AdjustSpeed.hpp"
#include "CheatsLibrary/Script_DamageCheat.hpp"
#include "CheatsLibrary/Script_SummonGoat.hpp"
#include "CheatsLibrary/Script_BeatLevel.hpp"
#include "CheatsLibrary/Script_FlipGoats.hpp"

Behavior_Cheats::Behavior_Cheats(Scene& scene, Object_Player& player, std::map<std::string,Text>& textObjects,
                               AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSpeedSound,
                               AudioSource& errorSound, AudioSource& beatGameSound, AudioSource& healSound,
                               AudioSource& flipSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::SPEED, std::make_shared<Script_AdjustSpeed>(speedUpSound,slowDownSound,resetSpeedSound,errorSound,true)));
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<Script_DamageCheat>(player, healSound, true)));
    scripts.insert(std::make_pair(Keys::GOAT, std::make_shared<Script_SummonGoat>(scene, player, true)));
    scripts.insert(std::make_pair(Keys::CHEATS, std::make_shared<Script_Cheats>(textObjects, true)));
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT, std::make_shared<Script_BeatLevel>(beatGameSound, true)));
    scripts.insert(std::make_pair(Keys::GOAT_FLIP, std::make_shared<Script_FlipGoats>(flipSound, true)));
}
