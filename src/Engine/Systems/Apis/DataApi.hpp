//
// Created by harley on 18-11-21.
//

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
    void Get(std::string table,std::string whereKey, std::string isValue);
    void Delete(DataModel model);

private:
    DataApi();
    std::unique_ptr<DataImpl> impl;
};
};

#endif //GOAT_ENGINE_DATAAPI_HPP
