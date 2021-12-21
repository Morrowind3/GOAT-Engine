#include "HttpClient.hpp"

using namespace Engine;

HttpClient::HttpClient(): _curl{ std::unique_ptr<CURL,void(*)(CURL*)> {curl_easy_init(), curl_easy_cleanup} } {
}

void* HttpClient::getClient() const {
    return _curl.get();
}