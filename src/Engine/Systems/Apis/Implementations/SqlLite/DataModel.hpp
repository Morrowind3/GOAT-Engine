#ifndef GOAT_ENGINE_DATAMODEL_HPP
#define GOAT_ENGINE_DATAMODEL_HPP


#include <string>
#include <utility>
#include <vector>
#include <map>

class DataModel {
public:
    explicit DataModel(std::string _tableName): tableName(std::move(_tableName)){};
    std::string getTableName();
    std::vector<std::string> getColumns();
    std::string getValue(std::string key);
    void setValue(std::string key, std::string value);
private:
    std::string tableName;
    std::map<std::string, std::string> data;
};


#endif //GOAT_ENGINE_DATAMODEL_HPP
