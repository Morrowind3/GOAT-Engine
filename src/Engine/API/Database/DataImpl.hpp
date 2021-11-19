//
// Created by harley on 18-11-21.
//

#ifndef GOAT_ENGINE_DATAIMPL_HPP
#define GOAT_ENGINE_DATAIMPL_HPP


#include <memory>
#include <sqlite3.h>

class DataImpl {
protected:
    DataImpl();
public:
    void Insert();
    void Update();
    void Get();
    void Delete();
private:
    void Start();
    void End();
    struct sql_destructor;
    std::unique_ptr<sqlite3, sql_destructor> pointer;
};


#endif //GOAT_ENGINE_DATAIMPL_HPP
