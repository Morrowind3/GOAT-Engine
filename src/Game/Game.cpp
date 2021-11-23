#include "../Engine/Engine.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "../Engine/Utilities/Debug.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    // Configure engine
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};
    GoatEngine engine{name, icon};
    Debug::getInstance().toggle(true);

    // Feed scenes
    EtappeOne etappeOne{};                          engine.sceneManager.AddScene(etappeOne);
    EtappeTwo etappeTwo{};                          engine.sceneManager.AddScene(etappeTwo);
    MainMenuScene mainMenu{engine.sceneManager};    engine.sceneManager.AddScene(mainMenu);

    engine.sceneManager.ChangeCurrentScene(mainMenu.name);

    engine.Run();
    return 0;
}