#include "../Engine/Engine.hpp"
#include "Scenes/Etappes/EtappeOne.hpp"
#include "Scenes/Etappes/EtappeTwo.hpp"
#include "Scenes/MainMenuScene.hpp"
#include "../Engine/Systems/Apis/DataApi.hpp"
#include "../Engine/Systems/Apis/Implementations/SqlLite/MigrationBuilder.hpp"
#include "../Engine/Utilities/Debug.hpp"

using namespace Engine;

void setupDatabase(){
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
    // Configure engine
    std::string name{"Mount Everestimate"};
    std::string icon{"icon.png"};
    std::string cursor{"cursor.png"};

    GoatEngine engine{name, icon, cursor};
    Debug::getInstance().toggle(true);

    // Feed scenes
    EtappeOne etappeOne{engine.sceneManager};
    engine.sceneManager.AddScene(etappeOne);
    EtappeTwo etappeTwo{};
    engine.sceneManager.AddScene(etappeTwo);
    MainMenuScene mainMenu{engine.sceneManager};
    engine.sceneManager.AddScene(mainMenu);

    engine.sceneManager.ChangeCurrentScene(mainMenu.name);

    if(!DataApi::getInstance().DatabaseExists()){
        setupDatabase();
    }

    engine.Run(60);

    return 0;
}

