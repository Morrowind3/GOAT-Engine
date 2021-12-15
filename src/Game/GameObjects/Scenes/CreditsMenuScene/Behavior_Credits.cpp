#include "Behavior_Credits.hpp"
#include "../../../Keys.hpp"
#include "Script_AnimateCreditsText.hpp"

Behavior_Credits::Behavior_Credits(const std::vector<Text*>& creditsText, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_AnimateCreditsText>(creditsText, true)));
}
