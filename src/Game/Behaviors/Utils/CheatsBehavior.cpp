#include "CheatsBehavior.hpp"
#include "Scripts/PauseScript.hpp."
#include "Scripts/CheatsScript.hpp"
#include "../../Keys.hpp"

CheatsBehavior::CheatsBehavior(std::map<std::string, Text>& textObjects, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::PAUSE, std::make_shared<PauseScript>(true)));
    scripts.insert(std::make_pair("CheatsScript", std::make_shared<CheatsScript>(textObjects, true)));
}
