#include "../Libraries/catch.hpp"
#include "../Engine/Systems/ScriptSystem.hpp"

using namespace Engine;

class TestScript: public Script {
    public: explicit TestScript(bool active): Script(active) {}
        void onStart() override {
            throw std::runtime_error("This shouldn't run");
        }
};

class TestBehavior: public Behavior {
    public: TestBehavior(bool activeSelf, bool activeScript): Behavior(activeSelf) {
        scripts.insert(std::make_pair("", std::make_shared<TestScript>(activeScript)));
    };
};

class TestObject: public GameObject {
    public: TestObject(bool activeSelf, bool activeBehavior, bool activeScript): GameObject(Transform{{}}, activeSelf) {
        behaviors.insert(std::make_pair("", std::make_shared<TestBehavior>(activeBehavior, activeScript)));
    }
};

TEST_CASE("Script system") {
    std::shared_ptr<Scene> exampleScene = std::make_shared<Scene>("Test", Rectangle{{},0,0});
    exampleScene->gameObjects.emplace_back(std::make_shared<TestObject>(false, false, false));

    ScriptSystem sut {};

    SECTION("Won't run inactive object") {
        // Act
        sut.onLoadScene(exampleScene);
        // Assert
        REQUIRE(true); // Nothing threw
    }

    SECTION("Won't run inactive behavior") {
        // Arrange
        exampleScene->gameObjects.front()->active = true;
        // Act
        sut.onLoadScene(exampleScene);
        // Assert
        REQUIRE(true); // Nothing threw
    }

    SECTION("Won't run inactive script") {
        // Arrange
        exampleScene->gameObjects.front()->active = true;
        exampleScene->gameObjects.front()->behaviors.front().second->active = true;
        // Act
        sut.onLoadScene(exampleScene);
        // Assert
        REQUIRE(true); // Nothing threw
    }

    SECTION("Will run script if object, behavior and script are all active") {
        // Arrange
        exampleScene->gameObjects.front()->active = true;
        exampleScene->gameObjects.front()->behaviors.front().second->active = true;
        exampleScene->gameObjects.front()->behaviors.front().second->scripts.front().second->active = true;
        try {
            sut.onLoadScene(exampleScene);
            // Assert (should throw)
            REQUIRE(false);
        } catch (const std::runtime_error& error) {
            REQUIRE(error.what() == std::string{"This shouldn't run"}); // The script ran!
        }
    }
    
}