#include "../Engine/Engine.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};

    GoatEngine engine{name, icon};

//     EtappeOne scene{};
    MainMenuScene scene{};
    engine.sceneManager.AddScene(scene);

    engine.Run();
    return 0;
}