#include "DataModel.hpp"

DataModel::DataModel(std::string tableName) : _tableName(std::move(tableName)) {
}

std::string DataModel::getTableName() const {
    return _tableName;
}

std::vector<std::string> DataModel::getColumns() const {
    std::vector<std::string> columns;
    columns.reserve(_data.size());
    for(auto& data : _data) {
        columns.push_back(data.first);
    }
    return columns;
}

std::string DataModel::getValue(const std::string& key) const {
    return _data.at(key);
}

void DataModel::setValue(const std::string& key, std::string value) {
    _data[key] = std::move(value);
}



