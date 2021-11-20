//
// Created by harley on 18-11-21.
//

#ifndef GOAT_ENGINE_DATAIMPL_HPP
#define GOAT_ENGINE_DATAIMPL_HPP


#include <memory>
#include <utility>
#include <sqlite3.h>
#include "../../../NoCopyNoMove.hpp"
#include "SqlLite/DataModel.hpp"

namespace Engine {

class DataImpl: NoCopyNoMove {
private:
    std::string databaseName;
    bool ExecuteQuery(std::string query);
    static bool checkResponseCode(int rc, char **err);
    static int callback(void *data, int argc, char **argv, char **azColName);
public:
    void RunMigrations(std::vector<std::basic_string<char>> migrationQueries);
    explicit DataImpl(std::string _databaseName): databaseName(std::move(_databaseName)){};
    void Insert(DataModel model);
    void Update(DataModel model);
    void Delete(DataModel model);
    bool DatabaseExists();

    DataModel Get(std::string table,std::string whereKey, std::string isValue);
    std::vector<DataModel> GetAll(std::string table, std::string orderBy = "", bool descending = false);

};
};

#endif //GOAT_ENGINE_DATAIMPL_HPP
