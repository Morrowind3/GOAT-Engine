#ifndef GOAT_ENGINE_SQLTABLE_HPP
#define GOAT_ENGINE_SQLTABLE_HPP

#include <utility>
#include <vector>
#include <map>
#include "SqlColumn.hpp"
#include "ForeignKey.hpp"

namespace Engine {
    class MigrationBuilder; // Friend class link
    class SqlTable {
        public:
            explicit SqlTable(std::string tableName);
            [[nodiscard]] std::vector<SqlColumn> getColumns() const;
            [[nodiscard]] std::vector<ForeignKey> getForeignKeys() const;
            [[nodiscard]] std::string getTableName() const;
            void setTableName(std::string tableName);
        private:
            friend class Engine::MigrationBuilder;
            std::string _tableName;
            std::vector<SqlColumn> _columns;
            std::vector<ForeignKey> _foreignKeys;
    };
}

#endif //GOAT_ENGINE_SQLTABLE_HPP
