#include "SqlColumn.hpp"

#include <utility>

using namespace Engine;

SqlColumn::SqlColumn(bool isPrimaryKey, std::string columnName, std::string type, bool nullable, bool isUnique):
        _isPrimaryKey{isPrimaryKey}, _columnName{std::move(columnName)}, _type{std::move(type)}, _isNullable{nullable}, _isUnique{isUnique} {
}

std::string SqlColumn::getName() const {
    return _columnName;
}

std::string SqlColumn::getType() const {
    return _type;
}

bool SqlColumn::isPrimaryKey() const {
    return _isPrimaryKey;
}

bool SqlColumn::isUnique() const {
    return _isUnique;
}

bool SqlColumn::isNullable() const {
    return _isNullable;
}
