#include "Keys.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/Systems/Apis/DataApi.hpp"
#include "../Engine/Systems/Apis/Implementations/SqlLite/MigrationBuilder.hpp"
#include "../Engine/Utilities/Debug.hpp"
#include "GameSceneManager.hpp"

using namespace Engine;

void setupDatabase() {
    MigrationBuilder migrations;
    migrations.NewTable("settings");
    migrations.AddColumn("fullscreen", "BOOLEAN", false, false, false);
    migrations.AddColumn("difficulty", "INTEGER", false, false, false);
    migrations.AddColumn("volume", "INTEGER", false, false, false);

    migrations.NewTable("level");
    migrations.AddColumn("completed", "BOOLEAN", false, true, false);
    migrations.AddColumn("all_garbage_collected", "BOOLEAN", false, false, false);
    migrations.AddColumn("name", "TEXT", false, false, false);

    migrations.NewTable("leaderboard");
    migrations.AddColumn("date", "TEXT", false, true, false);
    migrations.AddColumn("game_time", "INTEGER", false, false, false);
    migrations.AddColumn("score", "INTEGER", false, false, false);
    migrations.AddColumn("level_id", "INTEGER", false, false, false);
    migrations.AddForeignKey("id", "level");

    DataApi::getInstance().RunMigrations(migrations.getMigrationQueries());

    DataModel settings("settings");
    settings.setValue("fullscreen", "true");
    settings.setValue("volume", "100");
    settings.setValue("difficulty", "100");
    DataApi::getInstance().Insert(settings);
}

int main(int argc, char* args[]) {
    try {
        // Configure engine
        std::unique_ptr<SceneManager> sceneManager = std::make_unique<GameSceneManager>();
        sceneManager->ChangeCurrentScene(Keys::ETAPPE_TWO);
        std::string name{"Mount Everestimate"};
        std::string icon{"icon.png"};
        std::string cursor{"cursor.png"};
        // Unique pointer used to make sure the <i>potentially</i> memory-intensive Goat Engine is in the heap
        std::unique_ptr<GoatEngine> engine = std::make_unique<GoatEngine>(*sceneManager, name, icon, cursor);
        Debug::GetInstance().toggle(true);

        if(!DataApi::getInstance().DatabaseExists()) {
            setupDatabase();
        }

        engine->Run(60);
        return 0;
    } catch (const std::runtime_error& error) {
        Debug::GetInstance().log(error.what());
        return 1;
    } catch (...) {
        Debug::GetInstance().log("Fatal uncatchable error thrown!");
        return 2;
    }
}

