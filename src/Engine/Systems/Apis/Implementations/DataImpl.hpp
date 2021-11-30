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
            bool executeQuery(const std::string& query);
            static bool checkResponseCode(int rc, char **err);
            static int callback(void *data, int argc, char **argv, char **azColName);
        public:
            explicit DataImpl(std::string _databaseName): databaseName(std::move(_databaseName)){};
            void runMigrations(std::vector<std::basic_string<char>> migrationQueries);
            void insert(DataModel model);
            void update(DataModel model);
            void remove(DataModel model);
            bool databaseExists();

            DataModel get(const std::string& table, const std::string& whereKey, const std::string& isValue);
            std::vector<DataModel> getAll(const std::string& table, const std::string& orderBy, bool descending);
        };
};

#endif //GOAT_ENGINE_DATAIMPL_HPP
