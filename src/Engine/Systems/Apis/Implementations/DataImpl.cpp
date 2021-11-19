//
// Created by harley on 18-11-21.
//

#include <string>
#include <iostream>
#include "DataImpl.hpp"
#include "SqlLite/Migrations.h"

using namespace Engine;

void DataImpl::Start() {

}

void DataImpl::End() {

}

void DataImpl::Insert(DataModel model) {
    Start();

    std::string query = "INSERT INTO " + model.getTableName() + "(";
    std::vector<std::string> columns = model.getColumns();

    for(int i = 0; i < columns.size(); ++i){
        query += columns.at(i);
        if(i < columns.size()-1){
            query += ", ";
        }
    }
    query += ") VALUES (";
    for(int i = 0; i < columns.size(); ++i){
        query += model.getValue(columns.at(i));
        if(i < columns.size()-1){
            query += ", ";
        }
    }

    query += ")";
    std::cout << query << std::endl;
    wrapper->ExecuteQuery(query);

//    End();
}
void DataImpl::Update(DataModel model) {
    Start();
    std::string query = "UPDATE " + model.getTableName() + " SET ";
    for(auto& column : model.getColumns()) {
        query += column + "= " + model.getValue(column);
    }
    query += " WHERE id = " + model.getValue("id");
    wrapper->ExecuteQuery(query);

//    End();
}
void DataImpl::Delete(DataModel model) {
    Start();
    std::string query = "DELETE FROM " + model.getTableName() + " WHERE id = '" + model.getValue("id") +"';";
    wrapper->ExecuteQuery(query);

//    End();
}
DataModel DataImpl::Get(std::string table,std::string whereKey, std::string isValue ) {
    Start();
    std::string query = "SELECT * FROM " + table + " WHERE " + whereKey + " = '" + isValue +"';";
    wrapper->ExecuteQuery(query);


    DataModel model(table);
    return model;
    //build model from SQL data
//    End();
}

std::vector<DataModel> DataImpl::GetAll(std::string table, std::string orderBy, bool descending) {
    Start();
    std::string direction;
    if(descending){
        direction = "DESC";
    } else {
        direction = "ASC";
    }
    std::string query = "SELECT * FROM " + table + " ORDER BY " + orderBy + " " + direction + ";";
    wrapper->ExecuteQuery(query);



    std::vector<DataModel> vector;
    return vector;
    //build model from SQL data
//    End();
}

DataImpl::DataImpl() {
    wrapper = std::make_unique<SQlite>("savedData.db");
    auto migrations = std::make_unique<Migrations>(wrapper);
    std::vector<std::string> tables = migrations->createTables();
    for (int i = 0; i < tables.size(); ++i) {
        if (!wrapper->ExecuteQuery(tables.at(i))) {
            std::cout << "Table failed to create" << std::endl;
        }
    }

}

