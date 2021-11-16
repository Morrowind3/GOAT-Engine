#include "../Engine/Engine.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    GoatEngine engine{};

//     EtappeOne scene{};
    MainMenuScene scene{};
    engine.sceneManager.AddScene(scene);

    engine.Run();
    return 0;
}