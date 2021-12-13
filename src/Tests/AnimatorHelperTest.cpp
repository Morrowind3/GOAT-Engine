#include "../Libraries/catch.hpp"
#include "../Engine/Systems/SystemHelpers/AnimatorHelper.hpp"

using namespace Engine;

TEST_CASE("Animator Helper") {
    const uint16_t fps = 60.0;
    const double deltaTimeAtGivenFps = 1000.0 / fps;
    // Sprite A starts in active state, the rest in an inactive state
    Sprite spriteA {"",true}, spriteB {"",false}, spriteC {"",false};

    Animator animatorEmpty {fps,true,true};

    Animator animatorOne {fps, true, true};
    animatorOne.sprites.emplace_back(&spriteA);

    Animator animatorThree {fps, true, true};
    animatorThree.sprites.emplace_back(&spriteA);
    animatorThree.sprites.emplace_back(&spriteB);
    animatorThree.sprites.emplace_back(&spriteC);

    AnimatorHelper sut {};
    sut.handleAnimator(animatorEmpty,deltaTimeAtGivenFps);
    sut.handleAnimator(animatorOne,deltaTimeAtGivenFps);
    sut.handleAnimator(animatorThree,deltaTimeAtGivenFps);
    SECTION("First registration of animator doesn't animate the animator") {
        // Assert
        REQUIRE(spriteA.active); REQUIRE(!spriteB.active); REQUIRE(!spriteC.active);
    }
    SECTION("Animator disables active frame and enables the frame after it") {
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(!spriteA.active); REQUIRE(spriteB.active); REQUIRE(!spriteC.active);
    }
    SECTION("Animator properly handles multiple ticks") {
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps * 2);
        // Assert
        REQUIRE(!spriteA.active); REQUIRE(!spriteB.active); REQUIRE(spriteC.active);
    }
    SECTION("Animator handles edge case where the last frame is active at animation time") {
        // Arrange
        spriteA.active = false; spriteC.active = true;
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(spriteA.active); REQUIRE(!spriteB.active); REQUIRE(!spriteC.active);
    }
    SECTION("Animator sets first frame as active if all sprites are inactive") {
        // Arrange
        spriteA.active = false;
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(spriteA.active); REQUIRE(!spriteB.active); REQUIRE(!spriteC.active);
    }
    SECTION("Animator sets second frame as active if all are active, because it detects the first one as active") {
        // Arrange
        spriteA.active = true; spriteB.active = true; spriteC.active = true;
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(!spriteA.active); REQUIRE(spriteB.active); REQUIRE(!spriteC.active);
    }
    SECTION("Animator that doesn't loop will stop at the last sprite") {
        // Arrange
        animatorThree.loop = false;
        // Act
        sut.handleAnimator(animatorThree, deltaTimeAtGivenFps*3); // Should usually "overflow" to first sprite
        // Assert
        REQUIRE(!spriteA.active); REQUIRE(!spriteB.active); REQUIRE(spriteC.active);
    }
    SECTION("Empty animator doesn't crash") {
        // Act / Assert (assertion by not crashing)
        sut.handleAnimator(animatorEmpty, deltaTimeAtGivenFps);
    }
    SECTION("Single animator with active frame makes the frame stay active") {
        // Act
        sut.handleAnimator(animatorOne, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(spriteA.active);
    }
    SECTION("Single animator with inactive frame makes the frame become active") {
        // Arrange
        spriteA.active = false;
        // Act
        sut.handleAnimator(animatorOne, deltaTimeAtGivenFps);
        // Assert
        REQUIRE(spriteA.active);
    }
}