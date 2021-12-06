#include "SharedEtappe.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../GameObjects/Meta/Cheats.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/EtappeEnd/GameStateManager.hpp"
#include "../../GameObjects/Meta/Hud/FpsMeter.hpp"
#include "../../GameObjects/Meta/Etappes/BackToEtappeSelectionButton.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, SceneManager& sceneManager, Point dimensions,
    const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset): Scene(etappeKey,dimensions,{{0,0},1440,765}){
    // Etappe layer groups
    layerGroups.insert(std::make_pair(1, LayerGroup{false, 0.2})); // Parallax background
    layerGroups.insert(std::make_pair(99, LayerGroup{false, 0.01})); // Etappe text
    layerGroups.insert(std::make_pair(140, LayerGroup{})); // Tiles back
    layerGroups.insert(std::make_pair(150, LayerGroup{})); // Characters
    layerGroups.insert(std::make_pair(160, LayerGroup{})); // Tiles front
    layerGroups.insert(std::make_pair(0xffffffff, LayerGroup{true})); // UI

    // TODO: DELETE: Old layer groups
    /*FPS = 0xffffffff,
    UI = 200,
    PARALLAX_BACKGROUND = 80,
    CHARACTER = 150,
    TILES_FRONT = 160,
    TILES_BACK = 140,
    ETAPPE_TEXT = 99*/
    // Reset game state: Edmund no longer won or lost the level
    Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFAULT);

    // Hud
    // Hearts (hud)
    gameObjects.emplace_back(std::make_shared<LifeHeart>(1,
        Transform{{0,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(2,
        Transform{{105,0},LAYER::UI,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(3,
        Transform{{210,0},LAYER::UI,0,5,5},true));

    // Level constructor doing its magic
    MountEverestimateLevelConstructor{*this, fileLocation, tileSize, columns, rows, scale}.construct(xOffset, yOffset);
    _camera.trackObject(player);

    // Objects needed to have a functional etappe
    gameObjects.emplace_back(std::make_shared<GameStateManager>(sceneManager, true));
    gameObjects.emplace_back(std::make_shared<Cheats>(sceneManager, *this, *player, true));
    gameObjects.emplace_back(std::make_shared<BackToEtappeSelectionButton>(sceneManager,  // A start of a pause menu
    Transform{{1600,100},LAYER::UI, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}
