//
// Created by harley on 18-11-21.
//

#ifndef GOAT_ENGINE_DATAIMPL_HPP
#define GOAT_ENGINE_DATAIMPL_HPP


#include <memory>
#include <sqlite3.h>
#include "../../../NoCopyNoMove.hpp"
#include "SqlLite/SQlite.h"
#include "SqlLite/DataModel.hpp"

namespace Engine {

class DataImpl: NoCopyNoMove {
private:
    std::unique_ptr<SQlite> wrapper;
    void Start();
    void End();
public:
    DataImpl();
    void Insert(DataModel model);
    void Update(DataModel model);
    void Delete(DataModel model);

    DataModel Get(std::string table,std::string whereKey, std::string isValue);
    std::vector<DataModel> GetAll(std::string table, std::string orderBy = "", bool descending = false);
};
};

#endif //GOAT_ENGINE_DATAIMPL_HPP
