//
// Created by Morrowind3 on 10/12/2021.
//

#include <iostream>
#include "Http.hpp"
#include <regex>
#include <string>
#include <io.h>

size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata)
{
    FILE* stream = (FILE*)userdata;
    if (!stream)
    {
        printf("!!! No stream\n");
        return 0;
    }

    size_t written = fwrite((FILE*)ptr, size, nmemb, stream);
    return written;
}

std::string Http::imageFromWeb(const std::string& url) const {
    if(!isSupportedFormat(url)) return "";
    mkdir(_downloadDirectory.c_str());
    std::regex filenameRegex("([^\\/]+$)");
    std::smatch match;
    std::string filePathString;

    if (std::regex_search(url.begin(), url.end(), match, filenameRegex)){
        filePathString = _downloadDirectory + match[0].str();
        printf(filePathString.c_str());

    } else return "";

    FILE* fp = fopen(filePathString.c_str(), "wb");
    if (!fp)
    {
        printf("Failed to create file on the disk\n");
        return "";
    }

    curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, 1);

    CURLcode rc = curl_easy_perform(_curl);
    if (rc)
    {
        printf("Failed to download: %s\n", url.c_str());
        return "";
    }

    long res_code = 0;
    curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201)))
    {
        printf("Response code: %d\n", res_code);
        return "";
    }

    fclose(fp);
    return filePathString;
}



Http::Http() {
    curl_global_init(CURL_GLOBAL_ALL);
    _curl = curl_easy_init();
    curl_easy_setopt(_curl, CURLOPT_SSL_VERIFYPEER, 0L); //Disables SSL verification. Remove if class expands and this can start introducing security risks
    curl_easy_setopt(_curl, CURLOPT_VERBOSE, 0L);
}

Http::~Http(){
    curl_easy_cleanup(_curl);
    curl_global_cleanup();
}

bool Http::isSupportedFormat(const std::string &url) {
    std::string formats[1] {".png"};

    for(const auto& format : formats){
        if(url.size() >= format.size() &&
        url.compare(url.size() - format.size(), format.size(), format) == 0){
            return true;
        };
    }
    return false;
}
