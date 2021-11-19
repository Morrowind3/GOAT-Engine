//
// Created by ismet on 25-10-2021.
//

#include "Migrations.h"

std::vector<std::basic_string<char>> Migrations::createTables() {
    createHighScoreTable();
    createLevelTable();
    createSettingsTable();

    while (!tables.empty()) {
        allTablesQueries.push_back(sqLite->createTable(tables.back()));
        tables.pop_back();
    }
    return allTablesQueries;
}

void Migrations::createSettingsTable() {
    SqlTable *table = new SqlTable();

    table->setTableName("settings");
    SqlColumn *id = new SqlColumn(true, "id", "INTEGER", true, true);
    table->columns.push_back(id);
    SqlColumn *fullscreen = new SqlColumn(false, "fullscreen", "BOOLEAN", true, false);
    table->columns.push_back(fullscreen);
    SqlColumn *difficulty = new SqlColumn(false, "difficulty", "INTEGER", true, false);
    table->columns.push_back(difficulty);
    SqlColumn *volume = new SqlColumn(false, "volume", "INTEGER", true, false);
    table->columns.push_back(volume);

    allTablesQueries.push_back(sqLite->createTable(table));
}

void Migrations::createHighScoreTable() {
    SqlTable *table = new SqlTable();

    table->setTableName("highscores");
    SqlColumn *id = new SqlColumn(true, "id", "INTEGER", true, true);
    table->columns.push_back(id);
    SqlColumn *date = new SqlColumn(false, "date", "TEXT", true, false);
    table->columns.push_back(date);
    SqlColumn *gameTime = new SqlColumn(false, "game_time", "INTEGER", true, false);
    table->columns.push_back(gameTime);
    SqlColumn *score = new SqlColumn(false, "score", "INTEGER", true, false);
    table->columns.push_back(score);
    SqlColumn *name = new SqlColumn(false, "user_id", "TEXT", true, false);
    table->columns.push_back(name);
    SqlColumn *level_id = new SqlColumn(false, "level_id", "INTEGER", true, false);
    table->columns.push_back(level_id);

    ForeignKey *level_id_fk = new ForeignKey("level_id", "level", "id");
    table->forgeinKeys.push_back(level_id_fk);

    allTablesQueries.push_back(sqLite->createTable(table));
}

void Migrations::createLevelTable() {
    SqlTable *table = new SqlTable();

    table->setTableName("level");
    SqlColumn *id = new SqlColumn(true, "id", "INTEGER", true, true);
    table->columns.push_back(id);
    SqlColumn *completed = new SqlColumn(false, "completed", "BOOLEAN", true, false);
    table->columns.push_back(completed);
    SqlColumn *allGarbage = new SqlColumn(false, "all_garbage_collected", "BOOLEAN", true, false);
    table->columns.push_back(allGarbage);
    SqlColumn *levelName = new SqlColumn(false, "level_name", "TEXT", true, false);
    table->columns.push_back(levelName);

    allTablesQueries.push_back(sqLite->createTable(table));
}