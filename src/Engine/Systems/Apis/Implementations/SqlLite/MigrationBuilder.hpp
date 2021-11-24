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

    void NewTable(std::string name);
    void AddColumn(std::string name, std::string type, bool primaryKey, bool nullable, bool unique );
    void AddForeignKey(const std::string& referenceColumn, const std::string& referenceTable);
};


#endif //SQLITEPOC_MIGRATIONS_H
