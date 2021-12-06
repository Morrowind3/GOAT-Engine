#include "SharedEtappe.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/LifeHeart/LifeHeart.hpp"
#include "../../GameObjects/Scenes/GameStateManager.hpp"
#include "../../GameObjects/Utils/Cheats/Cheats.hpp"
#include "../../GameObjects/Scenes/Etappes/BackToEtappeSelectionButton.hpp"
#include "../../GameObjects/Utils/FpsMeter/FpsMeter.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, SceneManager& sceneManager, Point dimensions,
    const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset): Scene(etappeKey,dimensions,{{0,0},1440,765}){
    // Etappe layer groups
    layerGroups.insert(std::make_pair(LAYER::PARALLAX_BACKGROUND, LayerGroup{false, 0.2})); // Parallax background
    layerGroups.insert(std::make_pair(LAYER::ETAPPE_TEXT, LayerGroup{false, 0.5})); // Etappe text
    layerGroups.insert(std::make_pair(LAYER::TILES_BACK, LayerGroup{})); // Tiles back
    layerGroups.insert(std::make_pair(LAYER::CHARACTER, LayerGroup{})); // Characters
    layerGroups.insert(std::make_pair(LAYER::TILES_FRONT, LayerGroup{})); // Tiles front
    layerGroups.insert(std::make_pair(LAYER::UI, LayerGroup{true})); // UI

    // Reset game state: Edmund no longer won or lost the level
    Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFAULT);

    // Hud
    // Hearts (hud)
    gameObjects.emplace_back(std::make_shared<LifeHeart>(1,
        Transform{{0,0},LAYER::UI,100,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(2,
        Transform{{105,0},LAYER::UI,100,0,5,5},true));
    gameObjects.emplace_back(std::make_shared<LifeHeart>(3,
        Transform{{210,0},LAYER::UI,100,0,5,5},true));

    // Level constructor doing its magic
    MountEverestimateLevelConstructor{*this, fileLocation, tileSize, columns, rows, scale}.construct(xOffset, yOffset);
    _camera.trackObject(player);

    // Objects needed to have a functional etappe
    std::shared_ptr<Timer> timer = std::make_shared<Timer>(Transform{{0,0}}, true);
    gameObjects.emplace_back(std::make_shared<GameStateManager>(sceneManager, timer, true));
    gameObjects.emplace_back(std::make_shared<Cheats>(sceneManager, *this, *player, true));
    gameObjects.emplace_back(std::make_shared<BackToEtappeSelectionButton>(sceneManager,  // A start of a pause menu
    Transform{{1100,100},LAYER::UI, 0,0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}
