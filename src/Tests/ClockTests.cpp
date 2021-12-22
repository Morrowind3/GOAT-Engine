#include "../Libraries/catch.hpp"
#include "../Engine/Utilities/Clock.hpp"

using namespace Engine;

TEST_CASE("Clock") {
    Clock sut {};
    sut.setMaxFps(50);
    EngineCalls& engineCalls = EngineCalls::getInstance();

    SECTION("Can tick clock") {
        // Act
        while (!sut.tickAndCheckIfNextFrameIsReady()); // Frame one
        while (!sut.tickAndCheckIfNextFrameIsReady()); // Frame two
        // Assert
        REQUIRE(abs(sut.lastRecordedUnmodifiedDeltaTime() - 20) < 0.0001); // About 20ms to render a frame with no delay (1000/50=20)
        REQUIRE(sut.getTicks() == 40); // 40 ticks of 1ms to render two frames when the clock is set at 50FPS (20*2=40)
    }

    SECTION("Clock can modify its delta time based on engine speed") {
        // Arrange
        engineCalls.modifySpeed(2.0); // Engine runs twice as fast
        // Act
        while (!sut.tickAndCheckIfNextFrameIsReady()); // Process frame
        // Assert
        REQUIRE(abs(sut.lastRecordedUnmodifiedDeltaTime() - 20) < 0.0001); // Unmodified stays the same
        REQUIRE(abs(sut.gameStateBasedDeltaTime() - 40) < 0.0001); // Delta time fed to engine is doubled because engine speed is doubled
    }

    SECTION("Engine gets fed a delta time of 0 when engine is paused") {
        // Arrange
        engineCalls.pause(true); // Engine paused
        // Act
        while (!sut.tickAndCheckIfNextFrameIsReady()); // Process frame
        // Assert
        REQUIRE(abs(sut.lastRecordedUnmodifiedDeltaTime() - 20) < 0.0001); // Unmodified stays the same
        REQUIRE(sut.gameStateBasedDeltaTime() == 0); // Game state is modified
    }

}