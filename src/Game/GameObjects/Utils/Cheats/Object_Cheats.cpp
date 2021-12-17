#include "Object_Cheats.hpp"
#include "Behavior_Cheats.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"

Object_Cheats::Object_Cheats(Scene& scene, Object_Player& player, bool active) : GameObject(Transform{Point{0, 0}, LAYER::UI}, active) {
    // Show text to inform user (every line is a component)
    std::string font{"Fonts/Kenney_Thick.ttf"};
    uint8_t size{12};
    Color color{0, 0, 0, 255};
    text.insert(std::make_pair(Keys::CHEATS, Text{"Cheats", font, 16, color,
        Transform{{10, 130}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::CHEATS, Text{"Tilde - Show or hide this very menu", font, size, color,
        Transform{{10, 170}, transform.layerGroup, 1,0, 1, 1}, false}));

    text.insert(std::make_pair(Keys::CHEATS+Keys::FPS, Text{"1 - Show or hide FPS", font, size, color,
        Transform{{10, 210}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::GOAT, Text{"2 - Summon Goat", font, size, color,
        Transform{{10, 230}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::DAMAGE, Text{"3 - Damage Edmund", font, size, color,
        Transform{{10, 250}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::HP, Text{"4 - Heal Edmund", font, size, color,
        Transform{{10, 270}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::VICTORY_SCREEN, Text{"5 - Beat etappe", font, size, color,
        Transform{{10, 290}, transform.layerGroup, 1,0, 1, 1}, false}));

    text.insert(std::make_pair(Keys::CHEATS+Keys::SPEED_UP, Text{"PAGE UP - Speed up game speed", font, size, color,
        Transform{{10, 330}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::SLOW_DOWN, Text{"PAGE DOWN - Slow down game speed", font, size, color,
        Transform{{10, 350}, transform.layerGroup, 1,0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::RESET_SPEED, Text{"HOME - Reset game speed", font, size, color,
        Transform{{10, 370}, transform.layerGroup, 1,0, 1, 1}, false}));

    // Components required for cheats
    auto& speedUp = audioSources.insert(std::make_pair(Keys::SPEED_UP, AudioSource{"Sounds/SpeedUp.ogg",AudioSourceType::SAMPLE, true})).first->second;
    auto& slowDown = audioSources.insert(std::make_pair(Keys::SLOW_DOWN, AudioSource{"Sounds/SlowDown.ogg",AudioSourceType::SAMPLE, true})).first->second;
    auto& reset = audioSources.insert(std::make_pair(Keys::RESET_SPEED, AudioSource{"Sounds/Reset.ogg",AudioSourceType::SAMPLE, true})).first->second;
    auto& error = audioSources.insert(std::make_pair(Keys::ERROR, AudioSource{"Sounds/Error.ogg",AudioSourceType::SAMPLE, true})).first->second;
    auto& beatAGameButton = audioSources.insert(std::make_pair(Keys::VICTORY_SCREEN, AudioSource{"Sounds/BeatGame.ogg",AudioSourceType::SAMPLE, true})).first->second;
    auto& heal = audioSources.insert(std::make_pair(Keys::HP, AudioSource{"Sounds/Heal.ogg",AudioSourceType::SAMPLE, true})).first->second;

    // Object_Cheats
    behaviors.insert(std::make_pair(Keys::CHEATS, std::make_shared<Behavior_Cheats>(scene, player, this->text,
        speedUp, slowDown, reset, error, beatAGameButton, heal, true)));
}