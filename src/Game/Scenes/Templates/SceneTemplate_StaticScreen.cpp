#include "SceneTemplate_StaticScreen.hpp"
#include "../../GameObjects/Meta/Hud/FpsMeter.hpp"

SceneTemplate_StaticScreen::SceneTemplate_StaticScreen(const std::string& sceneName):
    Scene(sceneName,{1920,1020},{{0,0},1920,1020}) {
    gameObjects.emplace_back(std::make_shared<FpsMeter>(true));
}
