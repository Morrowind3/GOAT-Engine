#include "Cheats.hpp"
#include "../../Behaviors/Utils/CheatsBehavior.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"

Cheats::Cheats(Scene& scene, Player& player, bool active) : GameObject(Transform{Point{0, 0}, LAYER::UI}, active) {
    // Show text to inform user (every line is a component)
    std::string font{"Fonts/Kenney_Thick.ttf"};
    uint8_t size{12};
    Color color{0, 0, 0, 255};
    text.insert(std::make_pair(Keys::CHEATS, Text{"Cheats", font, size, color,
        Transform{{10, 150}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::CHEATS, Text{"Backtick - Show or hide this very menu", font, size, color,
        Transform{{10, 170}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::FPS, Text{"1 - Show or hide FPS", font, size, color,
        Transform{{10, 190}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::PLAYER, Text{"2 - Damage Edmund", font, size, color,
        Transform{{10, 210}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::GOAT, Text{"3 - Summon Goat", font, size, color,
        Transform{{10, 230}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::SPEED_UP, Text{"PAGE UP - Speed up game speed", font, size, color,
        Transform{{10, 250}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::SLOW_DOWN, Text{"PAGE DOWN - Slow down game speed", font, size, color,
        Transform{{10, 270}, transform.layer, 0, 1, 1}, false}));
    text.insert(std::make_pair(Keys::CHEATS+Keys::RESET_SPEED, Text{"HOME - Reset game speed", font, size, color,
        Transform{{10, 290}, transform.layer, 0, 1, 1}, false}));


    // Components required for cheats
    text.insert(std::make_pair(Keys::FPS, Text{"FPS", "Fonts/Fraps.ttf", 48,
                Color{0,0,0,255},
                Transform{Point{0,0},LAYER::FPS}, // ALWAYS on top!
                false}));

    audioSources.insert(std::make_pair(Keys::SPEED_UP, AudioSource{"Sounds/SpeedUp.ogg",AudioSourceType::SAMPLE, true}));
    audioSources.insert(std::make_pair(Keys::SLOW_DOWN, AudioSource{"Sounds/SlowDown.ogg",AudioSourceType::SAMPLE, true}));
    audioSources.insert(std::make_pair(Keys::RESET_SPEED, AudioSource{"Sounds/Reset.ogg",AudioSourceType::SAMPLE, true}));
    audioSources.insert(std::make_pair(Keys::ERROR, AudioSource{"Sounds/Error.ogg",AudioSourceType::SAMPLE, true}));

    // Cheats
    behaviors.insert(std::make_pair(Keys::CHEATS, std::make_shared<CheatsBehavior>(scene, player, this->text,
     audioSources.at(Keys::SPEED_UP), audioSources.at(Keys::SLOW_DOWN), audioSources.at(Keys::RESET_SPEED), audioSources.at(Keys::ERROR), true)));
}