
#ifndef SQLITEPOC_SQLTABLE_H
#define SQLITEPOC_SQLTABLE_H

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include "SqlColumn.hpp"
#include "ForeignKey.hpp"

class SqlTable {

public:
    std::vector<SqlColumn*> columns;
    std::vector<ForeignKey *> foreignKeys;

    std::vector<SqlColumn*> getColumns() const {
        return columns;
    };

    std::vector<ForeignKey *> getForeignKeys() const {
        return foreignKeys;
    };

    std::string getTableName() {
        return tableName;
    }

    void setTableName(std::string name) {
        tableName = std::move(name);
    }


private:
    std::string tableName;
};


#endif //SQLITEPOC_SQLTABLE_H
