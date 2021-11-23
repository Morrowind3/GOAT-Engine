#include "../Engine/Engine.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "Scenes/MainMenuScene.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};

    GoatEngine engine{name, icon};

    EtappeOne etappeOne{};
    EtappeTwo etappeTwo{};
    MainMenuScene mainMenu{engine.sceneManager};
    engine.sceneManager.AddScene(mainMenu);

    engine.Run();
    return 0;
}