//
// Created by ismet on 25-10-2021.
//

#ifndef SQLITEPOC_MIGRATIONS_H
#define SQLITEPOC_MIGRATIONS_H

#include <iostream>
#include <vector>
#include <map>
#include "SQlite.h"
#include "SqlColumn.h"
#include "SqlTable.h"

class Migrations {

private:
    std::unique_ptr<SQlite> &sqLite;
    std::vector<SqlTable *> tables;

public:
    Migrations(std::unique_ptr<SQlite> &sqLite) : sqLite(sqLite) {}
    std::vector<std::string> allTablesQueries;

    std::vector<std::basic_string<char>> createTables();

    void createSettingsTable();
    void createHighScoreTable();
    void createLevelTable();
};


#endif //SQLITEPOC_MIGRATIONS_H
