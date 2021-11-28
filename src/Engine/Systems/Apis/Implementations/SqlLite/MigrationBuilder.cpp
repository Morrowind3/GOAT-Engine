#include "MigrationBuilder.hpp"

std::vector<std::basic_string<char>> MigrationBuilder::getMigrationQueries() {
    while (!tables.empty()) {
        allTablesQueries.push_back(CreateTable(tables.back()));
        delete tables.back();
        tables.pop_back();
    }

    return allTablesQueries;
}

void MigrationBuilder::newTable(std::string name) {
    ++currentTable;
    tables.push_back(new SqlTable());
    tables.back()->setTableName(name);
    addColumn("id", "INTEGER", true, false, true);
}
void MigrationBuilder::addColumn(std::string name, std::string type, bool primaryKey, bool nullable, bool unique) {
    tables.back()->columns.push_back(new SqlColumn(primaryKey, std::move(name),  std::move(type), !nullable, unique));
}

void MigrationBuilder::addForeignKey(const std::string& referenceColumn, const std::string& referenceTable) {
    std::string keyName = referenceTable + "_" + referenceColumn;
    ForeignKey *level_id_fk = new ForeignKey(keyName, referenceTable, referenceColumn);
    tables.at(currentTable)->foreignKeys.push_back(level_id_fk);

}

std::string MigrationBuilder::CreateTable(SqlTable* table) {
    std::string sqlQuery = "CREATE TABLE IF NOT EXISTS " + table->getTableName() + "(";
    std::vector<SqlColumn *> columns = table->getColumns();

    for (int i = 0; i < columns.size(); ++i) {
        std::string column;
        if (i == 0) {
            column = columns[i]->getName() + " " + columns[i]->getType() + " ";
        } else {
            column = "," + columns[i]->getName() + " " + columns[i]->getType() + " ";
        }

        if (columns[i]->getPrimaryKey()) {
            column += "PRIMARY KEY ";
        }
        if (!columns[i]->isNullable()) {
            column += "NOT NULL ";
        }
        if (columns[i]->getUnique()) {
            column += "UNIQUE ";
        }
        sqlQuery += column;
    }

    if (!table->getForeignKeys().empty()) {
        std::vector<ForeignKey *> foreignKeys = table->getForeignKeys();

        for (int j = 0; j < foreignKeys.size(); ++j) {
            sqlQuery += ", FOREIGN KEY (" + foreignKeys.at(j)->getForeignKeyName() + ") REFERENCES " +
                        foreignKeys.at(j)->getReferenceTable() + "(" + foreignKeys.at(j)->getReferenceName() + ")";
        }
    }
    sqlQuery += ");";

    return sqlQuery;
}

