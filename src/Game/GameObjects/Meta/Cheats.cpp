#include "Cheats.hpp"
#include "../../Behaviors/Utils/CheatsBehavior.hpp"
#include "../../Keys.hpp"

Cheats::Cheats(bool active) : GameObject(Transform{Point{0, 0}}, active) {
    // Too bad, you can't render on new line, so you have to make every line a text object
    std::string font{"Fonts/Kenney_Thick.ttf"};
    uint8_t size{12};
    Color color{0, 0, 0, 255};

    Text text1{"Cheats", font, size, color,
            Transform{{10, 150}, transform.layer, 0, 1, 1},
            false};
    Text text2{"1 - Pause game", font, size, color,
            Transform{{10, 170}, transform.layer, 0, 1, 1},
               false};
    Text text3{"2 - Make character invincible TODO", font, size, color,
            Transform{{10, 190}, transform.layer, 0, 1, 1},
               false};

    text.insert(std::make_pair("CHEATS_1", text1));
    text.insert(std::make_pair("CHEATS_2", text2));
    text.insert(std::make_pair("CHEATS_3", text3));

    behaviors.insert(std::make_pair(Keys::CHEATS, std::make_shared<CheatsBehavior>(this->text, true)));
}