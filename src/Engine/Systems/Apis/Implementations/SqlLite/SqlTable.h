
#ifndef SQLITEPOC_SQLTABLE_H
#define SQLITEPOC_SQLTABLE_H

#include <iostream>
#include <vector>
#include <map>
#include "SqlColumn.h"
#include "ForeignKey.h"

class SqlTable {

public:
    std::vector<SqlColumn*> columns;
    std::vector<ForeignKey *> forgeinKeys;

    std::vector<SqlColumn*> getColumns() {
        return columns;
    };

    std::vector<ForeignKey *> getForeignKeys() {
        return forgeinKeys;
    };

    std::string getTableName() {
        return tableName;
    }

    void setTableName(std::string name) {
        tableName = name;
    }


private:
    std::string tableName;
    //key is foreignkey value is reference

};


#endif //SQLITEPOC_SQLTABLE_H
