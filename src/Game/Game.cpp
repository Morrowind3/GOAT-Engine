#include "Keys.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/Systems/Apis/DataApi.hpp"
#include "../Engine/Systems/Apis/Implementations/SqlLite/MigrationBuilder.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "GameSceneManager.hpp"

using namespace Engine;

void setupDatabase() {
    MigrationBuilder migrations;
    migrations.newTable("settings");
    migrations.addColumn("fullscreen", "BOOLEAN", false, false, false);
    migrations.addColumn("difficulty", "INTEGER", false, false, false);
    migrations.addColumn("volume", "INTEGER", false, false, false);

    migrations.newTable("level");
    migrations.addColumn("completed", "BOOLEAN", false, true, false);
    migrations.addColumn("all_garbage_collected", "BOOLEAN", false, false, false);

    migrations.newTable("leaderboard");
    migrations.addColumn("date", "TEXT", false, true, false);
    migrations.addColumn("game_time", "INTEGER", false, false, false);
    migrations.addColumn("score", "INTEGER", false, false, false);
    migrations.addColumn("level_id", "INTEGER", false, false, false);
    migrations.addForeignKey("id", "level");

    DataApi::getInstance().runMigrations(migrations.getMigrationQueries());

    DataModel settings("settings");
    settings.setValue("fullscreen", "true");
    settings.setValue("volume", "100");
    settings.setValue("difficulty", "100");
    DataApi::getInstance().insert(settings);
}

int main(int argc, char* args[]) {
    try {
        // Configure engine
        std::unique_ptr<SceneManager> sceneManager = std::make_unique<GameSceneManager>();
        sceneManager->changeCurrentScene(Keys::MAIN_MENU);
        std::string name{"Mount Everestimate"};
        std::string icon{"icon.png"};
        std::string cursor{"cursor.png"};
        // Unique pointer used to make sure the <i>potentially</i> memory-intensive Goat Engine is in the heap
        std::unique_ptr<GoatEngine> engine = std::make_unique<GoatEngine>(*sceneManager, name, icon, cursor);
        Debug::getInstance().toggle(true);

        if(!DataApi::getInstance().databaseExists()) {
            setupDatabase();
        }

        engine->run(60);
        return 0;
    } catch (const std::runtime_error& error) {
        std::string message {error.what()};
        Debug::getInstance().log("Runtime error: " + message);
        return 1;
    } catch (const std::exception& error) {
        std::string message {error.what()};
        Debug::getInstance().log("Exception: " + message);
        return 2;
    } catch (const std::string& error) {
        Debug::getInstance().log("String error: " + error);
        return 3;
    } catch (...) {
        Debug::getInstance().log("Fatal uncatchable error thrown!");
        return 4;
    }
}

