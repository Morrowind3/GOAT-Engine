//
// Created by ismet on 20-10-2021.
//

#ifndef SQLITEPOC_SQLITE_H
#define SQLITEPOC_SQLITE_H

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <regex>
#include "SqlColumn.h"
#include "SqlTable.h"

class SQlite {
private:
    char **err;
    const char *dbName;


public:
    explicit SQlite(const char* _dbName): dbName(_dbName){};
    static int SQlite::callback(void *data, int argc, char **argv, char **azColName);

    void runMigrations(int rc, sqlite3 *db, void *number, char **err);

    void defineTables();

    bool checkResponseCode(int rc, char **err);

    std::basic_string<char> createTable(SqlTable *table);

    bool ExecuteQuery(std::string query);

};


#endif //SQLITEPOC_SQLITE_H
