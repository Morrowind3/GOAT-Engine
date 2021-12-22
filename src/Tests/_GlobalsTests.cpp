/// This test has a prefix so that it defines CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN // Only needed once! Don't copy to other tests within this project.
#include <Windows.h>
#include "../Libraries/catch.hpp"
#include "../Engine/Utilities/Globals.hpp"

using namespace Engine;

TEST_CASE("Globals") {
    Globals& sut = Globals::getInstance();

    SECTION("Can store within scene without storing in game"){
        // Act
        sut.sceneStore("TEST", "TEST");
        // Assert
        REQUIRE(sut.sceneExists("TEST"));
        REQUIRE(!sut.gameExists("TEST"));
    }

    SECTION("Resetting scene removes all keys from scene") {
        // Arrange
        sut.sceneStore("TEST", "TEST");
        // Act
        sut.sceneReset();
        // Assert
        REQUIRE(!sut.sceneExists("TEST"));
    }

    SECTION("Throws when attempting to access invalid key") {;
        // Arrange
        const std::string invalidKey = "This key doesn't exist";
        // Act
        try {
            std::string suppressNoDiscardWarning = sut.gameGet(invalidKey);
        // Assert (should throw)
            REQUIRE(false);
        } catch (const std::runtime_error& error) {
            REQUIRE(error.what() == "The following key was not found in game globals: " + invalidKey);
        }
    }

}
