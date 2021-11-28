#include "DataApi.hpp"

using namespace Engine;

void DataApi::insert(DataModel model) {
    impl->insert(std::move(model));
}

void DataApi::update(DataModel model) {
    impl->update(std::move(model));
}

DataModel DataApi::get(const std::string& table, const std::string& whereKey, const std::string& isValue) {
    return impl->get(table, whereKey, isValue);
}

void DataApi::remove(DataModel model) {
    impl->remove(std::move(model));
}

DataApi::DataApi() {
    impl = std::make_unique<DataImpl>("StoredData.db");
}

void DataApi::runMigrations(std::vector<std::basic_string<char>> migrationQueries) {
    impl->runMigrations(std::move(migrationQueries));
}

bool DataApi::databaseExists() {
    return impl->databaseExists();
}

std::vector<DataModel> DataApi::getAll(std::string table, std::string orderBy, bool descending) {
    return impl->getAll(std::move(table), std::move(orderBy), descending);
}
