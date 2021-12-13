#include "SceneTemplate_Menu.hpp"
#include "../../GameObjects/Utils/FpsMeter/Object_FpsMeter.hpp"
#include "../../Layers.hpp"

SceneTemplate_Menu::SceneTemplate_Menu(const std::string& sceneName):
    Scene(sceneName,{1920,1020},{{0,0},1920,1020}) {
    layerGroups.insert(std::make_pair(LAYER::UI, LayerGroup{true})); // UI layer
    gameObjects.emplace_back(std::make_shared<Object_FpsMeter>(true));
}
