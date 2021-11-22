#include "../Engine/Engine.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};

    GoatEngine engine{name, icon};

    EtappeOne etappeOne{};
    EtappeTwo etappeTwo{};
    //MainMenuScene scene{};
    engine.sceneManager.AddScene(etappeTwo);

    engine.Run();
    return 0;
}