#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "SQlite.h"
#include "User.h"
#include "SqlColumn.h"
#include "Migrations.h"
#include "SQLUser.h"
#include "SqlQuery.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argv, char **argc) {
    auto ptr = std::make_unique<SQlite>();
    auto migrations = std::make_unique<Migrations>(ptr);
    std::vector<std::string> tables = migrations->createTables();

    for (int i = 0; i < tables.size(); ++i) {

        if (ptr->ExecuteQuery(tables.at(i))) {
            std::cout << "gelukt" << std::endl;
        } else {
            std::cout << "fucked" << std::endl;
        }
    }
    SQLUser *sqlUser = new SQLUser();

    //insert user

    User *user = new User("ismet", "ismet-my@hotmail.com");
    User *user2 = new User("mike", "mike@hotmail.com");
    std::string query = sqlUser->InsertUser(user);
    std::string query2 = sqlUser->InsertUser(user2);
    ptr->ExecuteQuery(query);
    ptr->ExecuteQuery(query2);
    ptr->ExecuteQuery("select * from user;");

    //update user
    user->setName("klaas");
    ptr->ExecuteQuery(sqlUser->UpdateUser(user));
    ptr->ExecuteQuery("select * from user;");

    ptr->ExecuteQuery(sqlUser->DeleteUser(user));
    ptr->ExecuteQuery("select * from user;");

    delete sqlUser;
    delete user;

    return 0;
}
