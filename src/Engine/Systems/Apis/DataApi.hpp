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
            void runMigrations(const std::vector<std::string>& migrationQueries);
            bool databaseExists();
            // CRUD
            void insert(const DataModel& model);
            std::vector<DataModel> getAll(const std::string& table, const std::string& orderBy = "", bool descending = false);
            DataModel get(const std::string& table, const std::string& whereKey, const std::string& isValue);
            void update(const DataModel& model);
            void remove(const DataModel& model);

        private:
            DataApi();
            std::unique_ptr<DataImpl> impl;
    };
};

#endif //GOAT_ENGINE_DATAAPI_HPP
