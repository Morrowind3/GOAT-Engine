#include "DataApi.hpp"

using namespace Engine;

DataApi::DataApi() {
    impl = std::make_unique<DataImpl>();
}

void DataApi::setDatabaseName(const std::string& databaseName) {
    impl->setDatabaseName(databaseName);
}

bool DataApi::databaseExists() {
    return impl->databaseExists();
}

void DataApi::runMigrations(std::vector<std::basic_string<char>> migrationQueries) {
    impl->runMigrations(std::move(migrationQueries));
}

void DataApi::insert(DataModel model) {
    impl->insert(std::move(model));
}

std::vector<DataModel> DataApi::getAll(const std::string& table, const std::string& orderBy, bool descending) {
    return impl->getAll(table, orderBy, descending);
}

DataModel DataApi::get(const std::string& table, const std::string& whereKey, const std::string& isValue) {
    return impl->get(table, whereKey, isValue);
}

void DataApi::update(DataModel model) {
    impl->update(std::move(model));
}

void DataApi::remove(DataModel model) {
    impl->remove(std::move(model));
}
