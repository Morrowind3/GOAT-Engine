#include "CheatsBehavior.hpp"
#include "Scripts/CheatsScript.hpp"
#include "Scripts/Cheats/SummonScript.hpp"
#include "Scripts/Cheats/DamageCheatScript.hpp"
#include "Scripts/Cheats/SpeedScript.hpp"
#include "../../Keys.hpp"
#include "Scripts/Cheats/BeatLevelScript.hpp"

CheatsBehavior::CheatsBehavior(SceneManager& sceneManager, Scene& scene, Player& player, std::map<std::string,Text>& textObjects,
                               AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSpeedSound,
                               AudioSource& errorSound, AudioSource& beatGameSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::SPEED, std::make_shared<SpeedScript>(speedUpSound,slowDownSound,resetSpeedSound,errorSound,true)));
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<DamageCheatScript>(player, true)));
    scripts.insert(std::make_pair(Keys::GOAT, std::make_shared<SummonScript>(scene, player, true)));
    scripts.insert(std::make_pair(Keys::CHEATS, std::make_shared<CheatsScript>(textObjects, true)));
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT, std::make_shared<BeatLevelScript>(sceneManager, beatGameSound, true)));
}
