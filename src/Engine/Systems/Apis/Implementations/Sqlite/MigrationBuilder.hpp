#ifndef GOATENGINE_MIGRATIONBUILDER_HPP
#define GOATENGINE_MIGRATIONBUILDER_HPP

#include <vector>
#include <map>

#include "SqlColumn.hpp"
#include "SqlTable.hpp"
#include "DataModel.hpp"

namespace Engine {
    class MigrationBuilder {
        public:
            std::vector<std::string> getMigrationQueries();
            void newTable(std::string name);
            void addColumn(std::string name, std::string type, bool primaryKey, bool nullable, bool unique);
            void addForeignKey(const std::string& referenceTable, const std::string& referenceColumn,
                               const std::string& referenceColumnType, bool thisColumnNullable, bool thisColumnUnique);
        private:
            int currentTable {-1};
            std::vector<SqlTable> _tables;
            std::vector<DataModel> _seeds;
            std::vector<std::string> _allTablesQueries;
            static std::string CreateTableCreationQuery(const SqlTable& table);
    };
}

#endif //GOATENGINE_MIGRATIONBUILDER_HPP
