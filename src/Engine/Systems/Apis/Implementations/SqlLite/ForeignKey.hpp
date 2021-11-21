//
// Created by ismet on 2-11-2021.
//

#ifndef SQLITEPOC_FOREIGNKEY_H
#define SQLITEPOC_FOREIGNKEY_H


#include <string>

class ForeignKey {
public:
    ForeignKey(std::string foreignKeyName, std::string referenceTable, std::string referenceName) {
        this->foreignKeyName = foreignKeyName;
        this->referenceName = referenceName;
        this->referenceTable = referenceTable;
    }

    std::string getForeignKeyName(){
        return foreignKeyName;
    }

    std::string getReferenceTable(){
        return referenceTable;
    }
    std::string getReferenceName(){
        return referenceName;
    }

private:
    std::string foreignKeyName;
    std::string referenceTable;
    std::string referenceName;
};


#endif //SQLITEPOC_FOREIGNKEY_H
