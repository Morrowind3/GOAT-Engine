#include "GameScenes.hpp"
#include "../Engine/Engine.hpp"

int main(int argc, char* args[]) {
    GoatEngine engine{};

    EtappeOne scene{};
    engine._sceneManager.AddScene(scene);

    engine.Run();
    return 0;
}