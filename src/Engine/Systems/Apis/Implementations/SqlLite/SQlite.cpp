#include "SQlite.h"

int SQlite::callback(void *data, int argc, char **argv, char **azColName){
    int i;

    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "");
    }

    printf("\n");
    return 0;
}


std::string SQlite::createTable(SqlTable *table) {
    std::string sqlQuery = "CREATE TABLE IF NOT EXISTS " + table->getTableName() + "(";
    std::vector<SqlColumn *> columns = table->getColumns();

    for (int i = 0; i < columns.size(); ++i) {
        std::string column;
        if (i == 0) {
            column = columns[i]->getName() + " " + columns[i]->getType() + " ";
        } else {
            column = "," + columns[i]->getName() + " " + columns[i]->getType() + " ";
        }

        if (columns[i]->getPrimaryKey()) {
            column += "PRIMARY KEY ";
        }
        if (!columns[i]->isNullable()) {
            column += "NOT NULL ";
        }
        if (columns[i]->getUnique()) {
            column += "UNIQUE ";
        }
        sqlQuery += column;
    }

    if (!table->getForeignKeys().empty()) {
        std::vector<ForeignKey *> foreignKeys = table->getForeignKeys();

        for (int j = 0; j < foreignKeys.size(); ++j) {
            sqlQuery += ", FOREIGN KEY (" + foreignKeys.at(j)->getForeignKeyName() + ") REFERENCES " +
                        foreignKeys.at(j)->getReferenceTable() + "(" + foreignKeys.at(j)->getReferenceName() + ")";
        }
    }
    sqlQuery += ");";

    return sqlQuery;
}

bool SQlite::ExecuteQuery(std::string query) {
    sqlite3 *db;
    int rc = sqlite3_open(dbName, &db);
    char **zErr = 0;
    if (checkResponseCode(rc, zErr)) {
        rc = sqlite3_exec(db, query.c_str(), callback, 0, zErr);
        if (!checkResponseCode(rc, zErr)) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            return false;
        }
        return true;
    }

    return false;
}

bool SQlite::checkResponseCode(int rc, char **err) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        return false;
    } else {
        return true;
    }
}
