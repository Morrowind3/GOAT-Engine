#ifndef GOATENGINE_SQLCOLUMN_HPP
#define GOATENGINE_SQLCOLUMN_HPP

#include <iostream>
#include <utility>

namespace Engine {
    class SqlColumn {
        public:
            SqlColumn(bool isPrimaryKey, std::string columnName, std::string type, bool nullable, bool isUnique);
            [[nodiscard]] std::string getName() const;
            [[nodiscard]] std::string getType() const;
            [[nodiscard]] bool isPrimaryKey() const;
            [[nodiscard]] bool isUnique() const;
            [[nodiscard]] bool isNullable() const;
        private:
            std::string _columnName;
            std::string _type;
            bool _isPrimaryKey;
            bool _isUnique;
            bool _isNullable;
    };
}

#endif //GOATENGINE_SQLCOLUMN_HPP
