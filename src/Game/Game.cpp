#include "../Engine/Engine.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "../Engine/Systems/Apis/DataApi.hpp"

using namespace Engine;

int main(int argc, char* args[]) {
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};

    GoatEngine engine{name, icon};

    EtappeOne scene{};
    //MainMenuScene scene{};
    engine.sceneManager.AddScene(scene);

    DataModel settings("Settings");
    settings.setValue("fullscreen", "true");
    settings.setValue("volume", "100");
    DataApi::getInstance().Insert(settings);


    engine.Run();


    return 0;
}