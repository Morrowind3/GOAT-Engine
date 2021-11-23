#include "MainMenu.hpp"

#include "../../Behaviors/SwitchSceneButtonBehavior.hpp"
#include "../../Behaviors/QuitGameBehavior.hpp"

MainMenu::MainMenu(SceneManager& sceneManager, Transform transform, bool active) : GameObject(transform, active) {
    // Start game
    buttons.insert(std::make_pair(Keys::START_GAME,Button{
        Text{"Start game", "Fonts/Kenney_Thick.ttf", 16, {0,0,0,255}, Transform{{0,0},300,0,6,6},true},
        Color{0,255,0,255},
        Rectangle{{0,0},1280,540},
        std::make_shared<SwitchSceneButtonBehavior>(Keys::ETAPPE_ONE, sceneManager,true),
        true}));

    // Quit game
    buttons.insert(std::make_pair(Keys::QUIT_GAME,Button{
            Text{"Quit game", "Fonts/Kenney_Thick.ttf", 16, {0,0,0,255}, Transform{{0,540},300,0,6,6},true},
            Color{255,0,0,255},
            Rectangle{{0,540},1280,540},
            std::make_shared<QuitGameBehavior>(true),
            true}));
}
