//
// Created by ismet on 22-10-2021.
//

#ifndef SQLITEPOC_SQLCOLUMN_H
#define SQLITEPOC_SQLCOLUMN_H

#include <iostream>
#include <utility>

class SqlColumn {

private:
    std::string name;
    bool isPrimaryKey;
    std::string type;
    bool nullable;
    bool isUnique;

public:
    SqlColumn(const bool isPrimaryKey, std::string columnName, std::string type, bool NotNull, bool isUnique) {
        this->isPrimaryKey = isPrimaryKey;
        this->name = std::move(columnName);
        this->type = std::move(type);
        this->nullable = NotNull;
        this->isUnique = isUnique;
    }

    std::string getName() {
        return name;
    }

    std::string getType(){
        return type;
    }

    bool getPrimaryKey() const {
        return isPrimaryKey;
    }

    bool getUnique() const {
        return isUnique;
    }

    bool isNullable() const {
        return nullable;
    }
};


#endif //SQLITEPOC_SQLCOLUMN_H
