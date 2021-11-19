//
// Created by harley on 18-11-21.
//

#include "DataApi.hpp"
using namespace Engine;

void DataApi::Insert(DataModel model) {
    impl->Insert(model);
}
void DataApi::Update(DataModel model) {
    impl->Update(model);
}
void DataApi::Get(std::string table,std::string whereKey, std::string isValue) {
    impl->Get(table,whereKey, isValue);
}
void DataApi::Delete(DataModel model) {
    impl->Delete(model);
}

DataApi::DataApi() {
    impl = std::make_unique<DataImpl>();
}
