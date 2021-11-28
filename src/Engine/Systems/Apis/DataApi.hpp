#ifndef GOAT_ENGINE_DATAAPI_HPP
#define GOAT_ENGINE_DATAAPI_HPP

#include <memory>
#include "Implementations/DataImpl.hpp"

namespace Engine {

    class DataApi {
        public:
            DataApi(DataApi const&) = delete;
            void operator=(DataApi const&) = delete;
            static DataApi& getInstance()
            {
                static DataApi instance;
                return instance;
            }
            void insert(DataModel model);
            void update(DataModel model);
            DataModel get(const std::string& table, const std::string& whereKey, const std::string& isValue);
            std::vector<DataModel> getAll(std::string table, std::string orderBy = "", bool descending = false);
            void remove(DataModel model);
            void runMigrations(std::vector<std::basic_string<char>> migrationQueries);
            bool databaseExists();

        private:
            DataApi();
            std::unique_ptr<DataImpl> impl;
    };
};

#endif //GOAT_ENGINE_DATAAPI_HPP
