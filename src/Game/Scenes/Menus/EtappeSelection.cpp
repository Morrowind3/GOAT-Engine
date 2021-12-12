#include "EtappeSelection.hpp"
#include "../../Keys.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/EtappeMarker.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/BackToMenuButton.hpp"
#include "../../GameObjects/Scenes/EtappeSelectionScene/EtappeSelectionBackground.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/decor/Cloud.hpp"

EtappeSelection::EtappeSelection(): SceneTemplate_Menu(Keys::ETAPPE_SELECT) {
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_ONE,1,1800,
        Transform{{1100,780},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_TWO,2,3700,
        Transform{{830,640},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_THREE,3,5000,
        Transform{{1070,510},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_FOUR,4,6640,
        Transform{{740,390},LAYER::UI,0,0,2.25,2.25},true));
    gameObjects.emplace_back(std::make_shared<EtappeMarker>(Keys::ETAPPE_FIVE,5,8848,
        Transform{{880,140},LAYER::UI,0,0,2.25,2.25},true));


    //Decorative clouds
    //TODO: Spawner? If the player stares at this screen for a few minutes it'll run out of clouds.
    gameObjects.emplace_back(std::make_shared<Cloud>(Cloud::Shape::BIG,
                                                            Transform{{630,140},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Cloud>(Cloud::Shape::WIDE,
                                                     Transform{{30,20},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Cloud>(Cloud::Shape::BIG,
                                                     Transform{{280,310},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Cloud>(Cloud::Shape::WIDE,
                                                     Transform{{0,500},LAYER::TILES_FRONT, 0, 0, 3, 3},true));
    gameObjects.emplace_back(std::make_shared<Cloud>(Cloud::Shape::SMALL,
                                                     Transform{{830,420},LAYER::TILES_FRONT, 0,0,3,3},true));

    gameObjects.emplace_back(std::make_shared<BackToMenuButton>(
            Transform{Point{20, 40}, LAYER::UI,0, 0, 4, 4}, true));

    gameObjects.emplace_back(std::make_shared<EtappeSelectionBackground>(Transform{{0,0},LAYER::PARALLAX_BACKGROUND},true));
}
