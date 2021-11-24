#ifndef GOAT_ENGINE_DATAAPI_HPP
#define GOAT_ENGINE_DATAAPI_HPP

#include <memory>
#include "Implementations/DataImpl.hpp"

namespace Engine{

class DataApi {
public:
    DataApi(DataApi const&) = delete;
    void operator=(DataApi const&) = delete;
    static DataApi& getInstance()
    {
        static DataApi instance;
        return instance;
    }
    void Insert(DataModel model);
    void Update(DataModel model);
    DataModel Get(const std::string& table,const std::string& whereKey, const std::string& isValue);
    std::vector<DataModel> GetAll(std::string table, std::string orderBy = "", bool descending = false);
    void Delete(DataModel model);
    void RunMigrations(std::vector<std::basic_string<char>> migrationQueries);
    bool DatabaseExists();

private:
    DataApi();
    std::unique_ptr<DataImpl> impl;
};
};

#endif //GOAT_ENGINE_DATAAPI_HPP
