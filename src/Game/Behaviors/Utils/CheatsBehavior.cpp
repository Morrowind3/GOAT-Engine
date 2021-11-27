#include "CheatsBehavior.hpp"
#include "Scripts/Cheats/PauseScript.hpp."
#include "Scripts/Cheats/FpsScript.hpp"
#include "Scripts/CheatsScript.hpp"
#include "../../Keys.hpp"

CheatsBehavior::CheatsBehavior(std::map<std::string, Text>& textObjects, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(true)));
    scripts.insert(std::make_pair(Keys::FPS,std::make_shared<FpsScript>(textObjects.at("FPS"), true)));
    scripts.insert(std::make_pair("CheatsScript", std::make_shared<CheatsScript>(textObjects, true)));
}
