#include "Keys.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/Systems/Apis/DataApi.hpp"
#include "../Engine/Systems/Apis/Implementations/Sqlite/MigrationBuilder.hpp"
#include "GameSceneManager.hpp"

using namespace Engine;

/// Database needs to be set up in order to be able to save
void setupDatabase() {
    DataApi& api = DataApi::getInstance();
    api.setDatabaseName("Mount_Everestisave.sav");
    if (api.databaseExists()) return; // Database already exists, don't overwrite it

    MigrationBuilder builder;
    builder.newTable("Players"); // Used to identify saves and store settings per player
    builder.addColumn("EtappesUnlocked", "INTEGER", false, false, false);

    builder.newTable("HighScores"); // Stores high scores per etappe, linked to a player
    builder.addColumn("EtappeNumber", "INTEGER", false, false, false);
    builder.addColumn("Score", "INTEGER", false, false, false);
    builder.addForeignKey("Players", "id", "INTEGER", false, false);

    api.runMigrations(builder.getMigrationQueries());
}

int main(int argc, char* args[]) {
    Debug& debug = Debug::getInstance();
    try {
        // Configure utilities
        debug.toggle(true);
        setupDatabase();

        // Configure engine
        std::unique_ptr<SceneManager> sceneManager = std::make_unique<GameSceneManager>();
        sceneManager->changeCurrentScene(Keys::SAVE_MENU);
        std::string name{"Mount Everestimate"};
        std::string icon{"icon.png"};
        std::string cursor{"cursor.png"};

        // Unique pointer used to make sure the <i>potentially</i> memory-intensive Goat Engine is in the heap
        std::unique_ptr<GoatEngine> engine = std::make_unique<GoatEngine>(*sceneManager, name, icon, cursor);

        engine->run(60);
        return 0;
    // Error handling
    } catch (const std::runtime_error& error) {
        std::string message {error.what()};
        debug.log("Runtime error: " + message);
        return 1;
    } catch (const std::exception& error) {
        std::string message {error.what()};
        debug.log("Exception: " + message);
        return 2;
    } catch (const std::string& error) {
        debug.log("String error: " + error);
        return 3;
    } catch (...) {
        debug.log("Fatal uncatchable error thrown!");
        return 4;
    }
}

