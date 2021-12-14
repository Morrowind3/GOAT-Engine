#include "Scene_EtappeSelectionMenu.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_EtappeMarker.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/Object_EtappeSelectionBackground.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/decor/Object_Cloud.hpp"

Scene_EtappeSelectionMenu::Scene_EtappeSelectionMenu(): SceneTemplate_Menu(Keys::ETAPPE_SELECT) {
    gameObjects.emplace_back(std::make_shared<Object_EtappeMarker>(Keys::ETAPPE_ONE,1,1800,
        Transform{{1100,780},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<Object_EtappeMarker>(Keys::ETAPPE_TWO,2,3700,
        Transform{{830,640},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<Object_EtappeMarker>(Keys::ETAPPE_THREE,3,5000,
        Transform{{1070,510},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<Object_EtappeMarker>(Keys::ETAPPE_FOUR,4,6640,
        Transform{{740,390},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<Object_EtappeMarker>(Keys::ETAPPE_FIVE,5,8848,
        Transform{{880,140},LAYER::UI,0,0,2.25,2.25},true));


    //Decorative clouds
    //TODO: Spawner? If the player stares at this screen for a few minutes it'll run out of clouds.
    gameObjects.emplace_back(std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::BIG,
                                                            Transform{{630,140},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::WIDE,
                                                     Transform{{30,20},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::BIG,
                                                     Transform{{280,310},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::WIDE,
                                                     Transform{{0,500},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Object_Cloud>(Object_Cloud::CloudShape::SMALL,
                                                     Transform{{830,420},LAYER::TILES_FRONT, 0,0,3,3},true));

    gameObjects.emplace_back(std::make_shared<Object_BackToMenuButton>(
            Transform{Point{20, 40}, LAYER::UI,0, 0, 4, 4}, true));

    gameObjects.emplace_back(std::make_shared<Object_EtappeSelectionBackground>(Transform{{0,0},LAYER::PARALLAX_BACKGROUND},true));
}
