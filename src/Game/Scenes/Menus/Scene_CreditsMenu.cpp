#include "Scene_CreditsMenu.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.hpp"
#include "../../GameObjects/Scenes/CreditsMenuScene/Object_CreditsMenuBackground.hpp"

Scene_CreditsMenu::Scene_CreditsMenu() : SceneTemplate_Menu(Keys::CREDITS_MENU) {
    gameObjects.emplace_back(std::make_shared<Object_CreditsMenuBackground>(
            Transform{Point{0, -50}, 0, 0,0, 1, 1}, true));

    gameObjects.emplace_back(std::make_shared<Object_BackToMenuButton>(
            Transform{Point{20, 40}, LAYER::UI,0, 0, 4, 4}, true));
}