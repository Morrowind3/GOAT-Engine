#include "../Libraries/catch.hpp"
#include "../Engine/Utilities/Input.hpp"

using namespace Engine;

TEST_CASE("Input registry") {
    InputRegistry sut {};

    SECTION("Input registry can store events") {
        // Act
        sut.storeKeyDown(KeyCode::A);
        sut.storeKeyUp(KeyCode::D);
        // Assert
        REQUIRE(sut.keyStatus(KeyCode::A) == PressState::PRESSED);
        REQUIRE(sut.keyStatus(KeyCode::D) == PressState::RELEASED);
    }

    SECTION("Input registry can flush as expected") {
        // Arrange
        sut.storeKeyDown(KeyCode::A);
        sut.storeKeyUp(KeyCode::D);
        // Act
        sut.flushForNextFrame();
        // Assert
        REQUIRE(sut.keyStatus(KeyCode::A) == PressState::HELD);
        REQUIRE(sut.keyStatus(KeyCode::D) == PressState::UNDETECTED);
    }

    SECTION("Input registry does not overwrite held state when new pressed event gets sent") {
        // Arrange
        sut.storeKeyDown(KeyCode::A);
        sut.flushForNextFrame();
        // Act
        sut.storeKeyDown(KeyCode::A);
        // Assert
        REQUIRE(sut.keyStatus(KeyCode::A) == PressState::HELD);
    }

    SECTION("Input that has not yet been registered gets implicit undetected state") {
        // Assert
        REQUIRE(sut.keyStatus(KeyCode::Y) == PressState::UNDETECTED);
    }

}
