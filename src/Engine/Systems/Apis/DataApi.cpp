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

void DataApi::runMigrations(const std::vector<std::string>& migrationQueries) {
    impl->runMigrations(migrationQueries);
}

void DataApi::insert(const DataModel& model) {
    impl->insert(model);
}

std::vector<DataModel> DataApi::getAll(const std::string& table, const std::string& orderBy, bool descending) {
    return impl->getAll(table, orderBy, descending);
}

DataModel DataApi::get(const std::string& table, const std::string& whereKey, const std::string& isValue) {
    return impl->get(table, whereKey, isValue);
}

void DataApi::update(const DataModel& model) {
    impl->update(model);
}

void DataApi::remove(const DataModel& model) {
    impl->remove(model);
}
