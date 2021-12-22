#include "ForeignKey.hpp"

using namespace Engine;

ForeignKey::ForeignKey(std::string foreignKeyName, std::string referenceTable, std::string referenceName):
    _foreignKeyName{std::move(foreignKeyName)}, _referenceTable{std::move(referenceTable)}, _referenceName{std::move(referenceName)} {
}

std::string ForeignKey::getForeignKeyName() const {
    return _foreignKeyName;
}

std::string ForeignKey::getReferenceTable() const {
    return _referenceTable;
}

std::string ForeignKey::getReferenceName() const {
    return _referenceName;
}
