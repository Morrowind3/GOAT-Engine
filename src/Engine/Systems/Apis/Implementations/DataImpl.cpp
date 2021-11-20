//
// Created by harley on 18-11-21.
//

#include <string>
#include <iostream>
#include <filesystem>
#include "DataImpl.hpp"

using namespace Engine;

void DataImpl::Insert(DataModel model) {
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
        query += model.getValue(columns.at(i));
        if(i < columns.size()-1){
            query += ", ";
        }
    }

    query += ")";
    std::cout << query << std::endl;
    ExecuteQuery(query);
}
void DataImpl::Update(DataModel model) {
    std::string query = "UPDATE " + model.getTableName() + " SET ";
    for(auto& column : model.getColumns()) {
        query += column + "= " + model.getValue(column);
    }
    query += " WHERE id = " + model.getValue("id");
    ExecuteQuery(query);
}
void DataImpl::Delete(DataModel model) {
    std::string query = "DELETE FROM " + model.getTableName() + " WHERE id = '" + model.getValue("id") +"';";
    ExecuteQuery(query);
}
DataModel DataImpl::Get(std::string table,std::string whereKey, std::string isValue ) {
    std::string query = "SELECT * FROM " + table + " WHERE " + whereKey + " = '" + isValue +"';";
    ExecuteQuery(query);
    DataModel model(table);
    return model;
}

std::vector<DataModel> DataImpl::GetAll(std::string table, std::string orderBy, bool descending) {
    std::string direction;
    if(descending){
        direction = "DESC";
    } else {
        direction = "ASC";
    }
    std::string query = "SELECT * FROM " + table + " ORDER BY " + orderBy + " " + direction + ";";
    ExecuteQuery(query);

    std::vector<DataModel> vector;
    return vector;
    //build model from SQL data
}

bool DataImpl::ExecuteQuery(std::string query) {
    sqlite3 *db;
    int rc = sqlite3_open(databaseName.c_str(), &db);
    char **zErr = 0;
    if (checkResponseCode(rc, zErr)) {
        rc = sqlite3_exec(db, query.c_str(), callback, 0, zErr);
        if (!checkResponseCode(rc, zErr)) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return false;
        }
        sqlite3_close(db);
        return true;
    }
    sqlite3_close(db);
    return false;
}

bool DataImpl::checkResponseCode(int rc, char** err) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        return false;
    } else {
        return true;
    }
}

int DataImpl::callback(void* data, int argc, char** argv, char** azColName) {
    for(int i = 0; i<argc; ++i){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "");
    }

    printf("\n");
    return 0;
}

void DataImpl::RunMigrations(std::vector<std::basic_string<char>> migrationQueries) {
    for (int i = 0; i < migrationQueries.size(); ++i) {
        if (!ExecuteQuery(migrationQueries.at(i))) {
            std::cout << "Table failed to create" << std::endl;
        }
    }
}

bool DataImpl::DatabaseExists() {
    return std::filesystem::exists(databaseName);
}

