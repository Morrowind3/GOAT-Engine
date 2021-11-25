#include "EtappeMarker.hpp"
#include "../../../Keys.hpp"
#include "../../../Behaviors/SwitchSceneButtonBehavior.hpp"
#include "../../../Behaviors/EtappeMarkerBehavior.hpp"

EtappeMarker::EtappeMarker(const std::string& levelKey, int levelNumber, unsigned short height, SceneManager& sceneManager,
                           Transform transform, bool active) : GameObject(transform, active) {

    // Star/flag special indicators // TODO: Delegate this to other game object for correct possitioning
    sprites.insert(std::make_pair(Keys::FLAG, Sprite{"Sprites/utils/flag/Flag.png", false}));
    sprites.insert(std::make_pair(Keys::STAR, Sprite{"Sprites/ui/rest/Star.png", false}));

    Transform textTransform{
            Point{transform.position.x+20, transform.position.y+20},
            transform.layer+1, 0, 1, 1};

    // Etappe height
    text.insert(std::make_pair(Keys::TEXT, Text{std::to_string(height)+"m", "Fonts/Kenney_Thick.ttf", 16,
        {0,0,0,255}, Transform{Point{transform.position.x+80,transform.position.y+25},LAYER::UI}, true}));

    // Disabled button
    buttons.insert(std::make_pair(Keys::FALSE, Button {
            Text{std::to_string(levelNumber), "Fonts/Kenney_Thick.ttf", 36, {0,0,0,255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/Button_square_gray.png", true},
            Rectangle{{transform.position.x, transform.position.y}, 200, 200},
            std::make_shared<Behavior>(false),
            true
    }));

    // Enabled button
    buttons.insert(std::make_pair(Keys::TRUE, Button {
            Text{std::to_string(levelNumber), "Fonts/Kenney_Thick.ttf", 36, {0,0,0,255}, textTransform, true},
            Sprite{"Sprites/ui/buttons/Button_square_green.png", true},
            Rectangle{{transform.position.x, transform.position.y}, 200, 200},
            std::make_shared<SwitchSceneButtonBehavior>(levelKey, sceneManager, true),
            false
    }));

    // Automatic configuration of this object
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<EtappeMarkerBehavior>(*this, levelNumber, true)));
}
