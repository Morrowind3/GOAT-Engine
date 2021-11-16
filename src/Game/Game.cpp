#include "../Engine/Engine.hpp"
#include "Scenes/MainMenuScene.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    GoatEngine engine{};

    MainMenuScene scene{};
    engine.sceneManager.AddScene(scene);

    engine.Run();
    return 0;
}