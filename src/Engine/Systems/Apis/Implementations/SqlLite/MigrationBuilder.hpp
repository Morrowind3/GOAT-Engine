#ifndef SQLITEPOC_MIGRATIONS_H
#define SQLITEPOC_MIGRATIONS_H

#include <iostream>
#include <vector>
#include <map>
#include "SqlColumn.hpp"
#include "SqlTable.hpp"
#include "DataModel.hpp"

class MigrationBuilder {

private:
    std::vector<SqlTable *> tables;
    std::vector<DataModel *> seeds;
    std::string CreateTable(SqlTable *table);
    int currentTable = -1;
public:
    std::vector<std::string> allTablesQueries;
    std::vector<std::basic_string<char>> getMigrationQueries();

    void newTable(std::string name);
    void addColumn(std::string name, std::string type, bool primaryKey, bool nullable, bool unique );
    void addForeignKey(const std::string& referenceTable, const std::string& referenceColumn,
                       const std::string& referenceColumnType, bool thisColumnNullable, bool thisColumnUnique);
};


#endif //SQLITEPOC_MIGRATIONS_H
