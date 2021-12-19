#ifndef GOAT_ENGINE_DATAAPI_HPP
#define GOAT_ENGINE_DATAAPI_HPP

#include <memory>
#include "Implementations/DataImpl.hpp"

namespace Engine {

    class DataApi {
        public:
            // Singleton
            DataApi(DataApi const&) = delete;
            void operator=(DataApi const&) = delete;
            static DataApi& getInstance() {
                static DataApi instance;
                return instance;
            }
            // Setup
            void setDatabaseName(const std::string& databaseName);
            void runMigrations(std::vector<std::basic_string<char>> migrationQueries);
            bool databaseExists();
            // CRUD
            void insert(DataModel model);
            std::vector<DataModel> getAll(const std::string& table, const std::string& orderBy = "", bool descending = false);
            DataModel get(const std::string& table, const std::string& whereKey, const std::string& isValue);
            void update(DataModel model);
            void remove(DataModel model);

        private:
            DataApi();
            std::unique_ptr<DataImpl> impl;
    };
};

#endif //GOAT_ENGINE_DATAAPI_HPP
