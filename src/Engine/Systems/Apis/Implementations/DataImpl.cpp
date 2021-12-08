#include <string>
#include <iostream>
#include <fstream>
#include "DataImpl.hpp"

using namespace Engine;

/// Essentials

bool DataImpl::databaseExists() {
    return std::ifstream{_databaseName.c_str()}.good();
}

void DataImpl::setDatabaseName(const std::string& databaseName) {
    _databaseName = databaseName;
}

void DataImpl::log(const char* errorMessage) {
    _debug.log(std::string{errorMessage});
}

bool DataImpl::executeQuery(const std::string& query) {
    sqlite3 *db;
    int responseCode = sqlite3_open(_databaseName.c_str(), &db);
    char **error = nullptr;
    if (checkResponseCode(responseCode)) {
        responseCode = sqlite3_exec(db, query.c_str(), callback, nullptr, error);
        if (!checkResponseCode(responseCode)) {
            log(sqlite3_errmsg(db));
            sqlite3_close(db);
            return false;
        }
        sqlite3_close(db);
        return true;
    }
    log(sqlite3_errmsg(db));
    sqlite3_close(db);
    return false;
}

bool DataImpl::checkResponseCode(int responseCode) {
    if (responseCode != SQLITE_OK) {
        return false;
    } else {
        return true;
    }
}

//Print out all columns and values for debugging
int DataImpl::callback(void* data, int argc, char** argv, char** azColName) {
    for(int i = 0; i<argc; ++i){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "");
    }
    printf("\n");
    return 0;
}

void DataImpl::runMigrations(const std::vector<std::basic_string<char>>& migrationQueries) {
    for (auto & migrationQuery : migrationQueries) {
        if (!executeQuery(migrationQuery)) {
            throw std::runtime_error("Table failed to create");
        }
    }
}

/// CRUD

void DataImpl::insert(DataModel model) {
    std::string query = "INSERT INTO " + model.getTableName() + "(";
    std::vector<std::string> columns = model.getColumns();

    for(int i = 0; i < columns.size(); ++i){
        query += columns.at(i);
        if(i < columns.size()-1){
            query += ", ";
        }
    }
    query += ") VALUES (";
    for(int i = 0; i < columns.size(); ++i){
        query += "'" + model.getValue(columns.at(i)) + "'";
        if(i < columns.size()-1){
            query += ", ";
        }
    }
    query += ")";
    executeQuery(query);
}

std::vector<DataModel> DataImpl::getAll(const std::string& table, const std::string& orderBy, bool descending) {
    std::string direction;
    if(descending){
        direction = "DESC";
    } else {
        direction = "ASC";
    }
    std::string query = "SELECT * FROM " + table;
    if(!orderBy.empty()){
        query += " ORDER BY " + orderBy + " " + direction + ";";
    }
    std::vector<DataModel> results;

    sqlite3 *db;
    sqlite3_stmt* statement;
    sqlite3_open(_databaseName.c_str(), &db);
    int responseCode = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    if (responseCode != SQLITE_OK) {
        std::cout << sqlite3_errmsg (db) << std::endl;
    }
    while(sqlite3_step(statement) != SQLITE_DONE){
        int columns = sqlite3_column_count(statement);
        DataModel model(table);
        for(int i = 0; i < columns; ++i){
            const char* name = sqlite3_column_name(statement, i);
            const char* value = reinterpret_cast<const char*>(sqlite3_column_text(statement, i));
            model.setValue(name, value);
        }
        results.push_back(model);
    }
    sqlite3_finalize (statement);
    sqlite3_close (db);

    return results;
}

DataModel DataImpl::get(const std::string& table, const std::string& whereKey, const std::string& isValue ) {
    std::string query = "SELECT * FROM " + table;
    if(!whereKey.empty() && !isValue.empty()){
        query += " WHERE " + whereKey + " = '" + "'" + isValue + "'" + "';";
    }
    sqlite3 *db;
    sqlite3_stmt* statement;
    sqlite3_open(_databaseName.c_str(), &db);
    int responseCode = sqlite3_prepare_v2(db, query.c_str(), -1, &statement, nullptr);
    if (responseCode != SQLITE_OK) {
        std::cout << sqlite3_errmsg (db) << std::endl;
    }
    sqlite3_step (statement);

    int columns = sqlite3_column_count(statement);
    DataModel model(table);
    for(int i = 0; i < columns; ++i){
        const char* name = sqlite3_column_name(statement, i);
        const char* value = reinterpret_cast<const char*>(sqlite3_column_text(statement, i));
        model.setValue(name, value);
    }
    sqlite3_finalize (statement);
    sqlite3_close (db);

    return model;
}

void DataImpl::update(DataModel model) {
    std::string query = "UPDATE " + model.getTableName() + " SET ";
    std::vector<std::string> columns = model.getColumns();

    for(int i = 0; i < columns.size(); ++i){
        query += columns.at(i) + " = " + "'" + model.getValue(columns.at(i)) + "'";
        if(i < columns.size()-1){
            query += ", ";
        }
    }
    query += " WHERE id = " + model.getValue("id");

    executeQuery(query);
}

void DataImpl::remove(DataModel model) {
    std::string query = "DELETE FROM " + model.getTableName() + " WHERE id = '" + model.getValue("id") +"';";
    executeQuery(query);
}
