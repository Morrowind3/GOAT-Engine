#include "CheatsBehavior.hpp"
#include "Scripts/Cheats/PauseScript.hpp."
#include "Scripts/Cheats/FpsScript.hpp"
#include "Scripts/CheatsScript.hpp"
#include "Scripts/Cheats/SummonScript.hpp"
#include "../../Keys.hpp"

CheatsBehavior::CheatsBehavior(
        std::map<std::string, Text>& textObjects,
        AudioSource& pauseSound,
        Scene& scene,
        Player& player,
        bool active
) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(pauseSound, true)));
    scripts.insert(std::make_pair(Keys::FPS, std::make_shared<FpsScript>(textObjects.at("FPS"), true)));
    scripts.insert(std::make_pair("SummonScript", std::make_shared<SummonScript>(scene, player, true)));
    scripts.insert(std::make_pair("CheatsScript", std::make_shared<CheatsScript>(textObjects, true)));
}
