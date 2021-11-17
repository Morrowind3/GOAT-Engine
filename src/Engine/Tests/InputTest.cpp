#define CATCH_CONFIG_MAIN
#include <Windows.h>
#include <SDL_events.h>
#include "../Utilities/Input.hpp"
#include "../../Libraries/catch.hpp"
#include "windows.h"


using namespace Engine;

//This test only works for windows. My linux (xfce) doesn't seem to have a decent api to simulate keystrokes without tight coupling with engine code/SDL.
#ifdef _WIN32
TEST_CASE("Keyboard"){
    Input& input = Input::getInstance();
    SDL_Event sdlevent = {};


    SECTION("A down"){
        sdlevent.type = SDL_KEYDOWN;
        sdlevent.key.keysym.sym = SDLK_a;
        SDL_PushEvent(&sdlevent);

        REQUIRE(input.GetKeyDown(Input::KeyCode::A) == true);
    }
    SECTION("Move up"){

    }
    SECTION("Move down"){
    }

    SECTION("Move left"){

    }
}
#endif
