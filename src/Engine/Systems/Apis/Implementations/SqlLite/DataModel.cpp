//
// Created by Morrowind3 on 19/11/2021.
//

#include "DataModel.hpp"

std::string DataModel::getTableName() {
    return tableName;
}

std::vector<std::string> DataModel::getColumns() {
    std::vector<std::string> columns;
    columns.reserve(data.size());
    for(auto& it : data) {
        columns.push_back(it.first);
    }
    return columns;
}

std::string DataModel::getValue(std::string key) {
    return data[key];
}

void DataModel::setValue(std::string key, std::string value) {
    data[key] = value;
}
