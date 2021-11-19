//
// Created by harley on 18-11-21.
//

#ifndef GOAT_ENGINE_DATAAPI_HPP
#define GOAT_ENGINE_DATAAPI_HPP


#include <memory>
#include "DataImpl.hpp"

class DataApi {
public:
    DataApi(DataApi const&) = delete;
    void operator=(DataApi const&) = delete;
    static DataApi& getInstance()
    {
        static DataApi instance;
        return instance;
    }
    void Start();
    void End();
private:
    DataApi() = default;

    std::unique_ptr<DataImpl> impl;
};


#endif //GOAT_ENGINE_DATAAPI_HPP
