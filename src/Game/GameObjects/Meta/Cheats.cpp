#include "Cheats.hpp"
#include "../../Behaviors/Utils/CheatsBehavior.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"

Cheats::Cheats(bool active) : GameObject(Transform{Point{0, 0}, LAYER::UI}, active) {
    // Too bad, you can't render on new line, so you have to make every line a text object
    std::string font{"Fonts/Kenney_Thick.ttf"};
    uint8_t size{12};
    Color color{0, 0, 0, 255};

    // TODO: Keys.hpp
    text.insert(std::make_pair("CHEATS_1", Text{"Cheats", font, size, color,
                                            Transform{{10, 150}, transform.layer, 0, 1, 1},
                                            false}));
    text.insert(std::make_pair("CHEATS_2", Text{"1 - Pause or unpause game", font, size, color,
                                            Transform{{10, 170}, transform.layer, 0, 1, 1},
                                            false}));
    text.insert(std::make_pair("CHEATS_3", Text{"2 - Show or hide FPS", font, size, color,
                                                Transform{{10, 190}, transform.layer, 0, 1, 1},
                                                false}));

    text.insert(std::make_pair("FPS", Text{"FPS", "Fonts/Fraps.ttf", 48,
                Color{0,0,0,255},
                Transform{Point{0,0},transform.layer}, // ALWAYS on top!
                false}));

    audioSources.insert(std::make_pair(Keys::PAUSE_SFX, AudioSource{"Sounds/Pause.ogg",AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::CHEATS, std::make_shared<CheatsBehavior>(this->text, audioSources.at(Keys::PAUSE_SFX), true)));
}