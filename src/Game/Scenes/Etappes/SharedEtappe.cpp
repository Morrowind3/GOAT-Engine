#include "SharedEtappe.hpp"
#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"
#include "../../MountEverestimateLevelConstructor.hpp"
#include "../../GameObjects/Meta/Cheats.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "../../Keys.hpp"
#include "../../Layers.hpp"
#include "../../GameObjects/Meta/EtappeEnd/GameStateManager.hpp"
#include "../../GameObjects/Meta/Hud/FpsMeter.hpp"

SharedEtappe::SharedEtappe(const std::string& etappeKey, Transform playerStartPosition, SceneManager& sceneManager,
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

    player = std::make_shared<Player>(playerStartPosition, true);
    gameObjects.emplace_back(player);
    _camera.trackObject(player);
    // Level constructor doing its magic
    MountEverestimateLevelConstructor{*this, fileLocation, tileSize, columns, rows, scale}.construct(xOffset, yOffset);

    // Cheats
    gameObjects.emplace_back(std::make_shared<Cheats>(*this, *player, true));
    // FPS
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}
