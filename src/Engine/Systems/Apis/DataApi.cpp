#include "DataApi.hpp"

#include <utility>
using namespace Engine;

void DataApi::Insert(DataModel model) {
    impl->Insert(std::move(model));
}
void DataApi::Update(DataModel model) {
    impl->Update(std::move(model));
}
DataModel DataApi::Get(const std::string& table,const std::string& whereKey, const std::string& isValue) {
    return impl->Get(table,whereKey, isValue);
}
void DataApi::Delete(DataModel model) {
    impl->Delete(std::move(model));
}

DataApi::DataApi() {
    impl = std::make_unique<DataImpl>("StoredData.db");
}

void DataApi::RunMigrations(std::vector<std::basic_string<char>> migrationQueries) {
    impl->RunMigrations(std::move(migrationQueries));
}

bool DataApi::DatabaseExists() {
    return impl->DatabaseExists();
}

std::vector<DataModel> DataApi::GetAll(std::string table, std::string orderBy, bool descending) {
    return impl->GetAll(std::move(table), std::move(orderBy), descending);
}
