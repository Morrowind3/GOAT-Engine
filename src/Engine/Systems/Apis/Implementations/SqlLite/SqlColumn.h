//
// Created by ismet on 22-10-2021.
//

#ifndef SQLITEPOC_SQLCOLUMN_H
#define SQLITEPOC_SQLCOLUMN_H

#include <iostream>

class SqlColumn {

private:
    char *name;
    bool isPrimaryKey;
    char *type;
    bool nullable;
    bool isUnique;

public:
    SqlColumn::SqlColumn(const bool isPrimaryKey, char *columnName, char *type, bool NotNull, bool isUnique) {
        this->isPrimaryKey = isPrimaryKey;
        this->name = columnName;
        this->type = type;
        this->nullable = NotNull;
        this->isUnique = isUnique;
    }

    std::string getName() {
        return name;
    }

    std::string getType(){
        return type;
    }

    bool getPrimaryKey() {
        return isPrimaryKey;
    }

    bool getUnique() {
        return isUnique;
    }

    bool isNullable() {
        return nullable;
    }
};


#endif //SQLITEPOC_SQLCOLUMN_H
