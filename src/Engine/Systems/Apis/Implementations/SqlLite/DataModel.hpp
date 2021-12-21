#ifndef GOAT_ENGINE_DATAMODEL_HPP
#define GOAT_ENGINE_DATAMODEL_HPP

#include <string>
#include <utility>
#include <vector>
#include <map>

class DataModel {
    public:
        explicit DataModel(std::string tableName);
        [[nodiscard]] std::string getTableName() const;
        [[nodiscard]] std::vector<std::string> getColumns() const;
        [[nodiscard]] std::string getValue(const std::string& key) const;
        void setValue(const std::string& key, std::string value);
    private:
        std::string _tableName;
        std::map<std::string, std::string> _data;
};


#endif //GOAT_ENGINE_DATAMODEL_HPP
