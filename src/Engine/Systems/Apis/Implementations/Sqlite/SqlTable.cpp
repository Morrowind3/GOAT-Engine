#include "SqlTable.hpp"

using namespace Engine;

SqlTable::SqlTable(std::string tableName): _tableName{std::move(tableName)} {
}

std::vector<SqlColumn> SqlTable::getColumns() const {
    return _columns;
}

std::vector<ForeignKey> SqlTable::getForeignKeys() const {
    return _foreignKeys;
}

std::string SqlTable::getTableName() const {
    return _tableName;
}

void SqlTable::setTableName(std::string tableName) {
    _tableName = std::move(tableName);
}
