#include "Scene_GameWonMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Scenes/GameWonScene/Object_GameWonSceneManager.hpp"
#include "../../GameObjects/Utils/Decor/Advertising/Object_AdvertisingPane.hpp"

Scene_GameWonMenu::Scene_GameWonMenu(): SceneTemplate_Menu(Keys::VICTORY_SCREEN) {
    gameObjects.emplace_back(std::make_shared<Object_GameWonSceneManager>( Transform{Point{0, 0}, 0,1, 0, 1, 1}, true));

    std::shared_ptr<Object_AdvertisingPane> topFlag = std::make_shared<Object_AdvertisingPane>( Transform{Point{1582, 355}, 0,1, 0, 1, 1}, true);
    topFlag->transform.forcedWidth = 172;
    topFlag->transform.forcedHeight = 100;
    gameObjects.emplace_back(topFlag);

    gameObjects.emplace_back(std::make_shared<Object_BackToMenuButton>(Transform{{25,25}, LAYER::UI, 0, 0, 8, 8}, true));
}
