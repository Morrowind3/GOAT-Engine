#include "MigrationBuilder.hpp"

using namespace Engine;

/// Add all tables to the migration query list
std::vector<std::string> MigrationBuilder::getMigrationQueries() {
    while (!_tables.empty()) {
        _allTablesQueries.push_back(CreateTableCreationQuery(_tables.front()));
        _tables.erase(_tables.begin());
    }
    return _allTablesQueries;
}

/// Adds new table with ID column as primary key
void MigrationBuilder::newTable(std::string name) {
    ++currentTable;
    _tables.emplace_back(SqlTable{std::move(name)});
    addColumn("id", "INTEGER", true, false, true);
}

/// Adds column to current table
void MigrationBuilder::addColumn(std::string name, std::string type, bool primaryKey, bool nullable, bool unique) {
    _tables.back()._columns.emplace_back(SqlColumn{primaryKey, std::move(name), std::move(type), nullable, unique});
}

/// Adds foreign key to current table
void MigrationBuilder::addForeignKey(const std::string& referenceTable, const std::string& referenceColumn,
                                     const std::string& referenceColumnType, bool thisColumnNullable, bool thisColumnUnique) {
    std::string keyName = referenceTable + "_" + referenceColumn;
    addColumn(keyName, referenceColumnType, false, thisColumnNullable, thisColumnUnique);
    _tables.at(currentTable)._foreignKeys.emplace_back(ForeignKey{keyName, referenceTable, referenceColumn});
}

/// Turn table into table creation query
std::string MigrationBuilder::CreateTableCreationQuery(const SqlTable& table) {
    std::string sqlQuery = "CREATE TABLE IF NOT EXISTS " + table.getTableName() + "(";
    std::vector<SqlColumn> columns = table.getColumns();

    /// Add columns
    for (int i = 0; i < columns.size(); ++i) {
        std::string column;
        if (i == 0) {
            column = columns[i].getName() + " " + columns[i].getType() + " ";
        } else {
            column = "," + columns[i].getName() + " " + columns[i].getType() + " ";
        }

        if (columns[i].isPrimaryKey()) {
            column += "PRIMARY KEY ";
        }
        if (!columns[i].isNullable()) {
            column += "NOT NULL ";
        }
        if (columns[i].isUnique()) {
            column += "UNIQUE ";
        }
        sqlQuery += column;
    }

    /// Add foreign keys
    for (auto & foreignKey : table.getForeignKeys()) {
        sqlQuery += ", FOREIGN KEY (" + foreignKey.getForeignKeyName() + ") REFERENCES " +
                    foreignKey.getReferenceTable() + "(" + foreignKey.getReferenceName() + ")";
    }

    sqlQuery += ");";
    return sqlQuery;
}

