#ifndef GOAT_ENGINE_HTTP_HPP
#define GOAT_ENGINE_HTTP_HPP

#include <string>
#include <vector>
#include <curl.h>

class Http {
public:
    Http(Http const&) = delete;
    ~Http();
    void operator=(Http const&) = delete;
    static Http& getInstance() {
        static Http instance;
        return instance;
    }
    std::string imageFromWeb(const std::string& url) const;

private:
    Http();
    static bool isSupportedFormat(const std::string &url);
    CURL* _curl;
    const std::string _downloadDirectory = ".\\sprites\\WebImages\\";
};


#endif //GOAT_ENGINE_HTTP_HPP
