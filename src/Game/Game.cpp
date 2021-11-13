#include "GameScenes.hpp"
#include "../Engine/Engine.hpp"

int main(int argc, char* args[]) {
    GoatEngine engine{SceneManager{SCENES}};
    engine.Run();
    return 0;
}