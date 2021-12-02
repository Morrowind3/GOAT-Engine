#define CATCH_CONFIG_MAIN //Only needed once! Don't copy to other tests within this project.
#include <Windows.h>
#include "../../catch.hpp"
#include "../Engine.hpp"
#include "../Utilities/Input.hpp"

using namespace Engine;

TEST_CASE("Game Loop"){
    Input& input = Input::getInstance();
    //universal-set up. Runs before every section.

    SECTION("Can do cool thing"){
        //Independently running tests. You can use input here.
        REQUIRE(true == true); //Assertion
    }
    SECTION("Can't do lame thing"){
        //You can use Input again here, unaffected by the cool thing test.
        REQUIRE("Lame" != "true");
    }
}
