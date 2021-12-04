#include "SharedEtappe.hpp"
#include "../../GameObjects/Utils/LifeHeart/LifeHeart.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../GameObjects/Utils/Cheats/Cheats.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Utils/FpsMeter/FpsMeter.hpp"
#include "../../GameObjects/Scenes/Etappes/BackToEtappeSelectionButton.hpp"
#include "../../GameObjects/Scenes/GameStateManager.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, SceneManager& sceneManager,
    const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset): Scene(etappeKey){
    Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFAULT);
    gameObjects.emplace_back(std::make_shared<GameStateManager>(sceneManager, true));

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

    gameObjects.emplace_back(std::make_shared<Cheats>(sceneManager, *this, *player, true));
    gameObjects.emplace_back(std::make_shared<BackToEtappeSelectionButton>(sceneManager,  // A start of a pause menu
    Transform{{1600,100},LAYER::UI, 0, 3, 3}, true));
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}
