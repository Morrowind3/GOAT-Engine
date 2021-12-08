#ifndef GOAT_ENGINE_DATAIMPL_HPP
#define GOAT_ENGINE_DATAIMPL_HPP

#include <memory>
#include <utility>
#include <sqlite3.h>
#include "../../../NoCopyNoMove.hpp"
#include "../../../Utilities/Debug.hpp"
#include "SqlLite/DataModel.hpp"

namespace Engine {
    class DataImpl: NoCopyNoMove {
        public:
            // Setup
            void setDatabaseName(const std::string& databaseName);
            void runMigrations(const std::vector<std::basic_string<char>>& migrationQueries);
            bool databaseExists();
            // CRUD
            void insert(DataModel model);
            std::vector<DataModel> getAll(const std::string& table, const std::string& orderBy, bool descending);
            DataModel get(const std::string& table, const std::string& whereKey, const std::string& isValue);
            void update(DataModel model);
            void remove(DataModel model);
        private:
            Debug& _debug = Debug::getInstance();
            std::string _databaseName;
            bool executeQuery(const std::string& query);
            static bool checkResponseCode(int responseCode);
            static int callback(void *data, int argc, char **argv, char **azColName);
            void log(const char *errorMessage);
        };
}

#endif //GOAT_ENGINE_DATAIMPL_HPP
