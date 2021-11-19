//
// Created by harley on 18-11-21.
//

#include "DataImpl.hpp"

DataImpl::DataImpl() {
    sqlite3_open();
}


struct sqlite3_deleter {
    void operator()(sqlite3* sql) {
        sqlite3_close_v2(sql);
    }
};
