#include "Http.hpp"
#include <io.h>

using namespace Engine;

extern "C" {
    /// Callback method for CURL
    size_t callback(void* contents, size_t size, size_t numberOfMembers, void* userData) {
        FILE* stream = (FILE*)userData;
        if (!stream) return 0;

        const size_t written = fwrite((FILE*)contents, size, numberOfMembers, stream);
        return written;
    }
}

/// Returns the string where the file was downloaded
std::string Http::downloadFromWeb(const std::string& url) const {
    std::string downloadLocation;

    if (isValidUrl(url)) {
        downloadLocation = _downloadDirectory + extractFilenameFromUrl(url);
    } else throw std::runtime_error("HTTP-Utility: Invalid URL: " + url);

    mkdir(_downloadDirectory.c_str());
    FILE* fp = fopen(downloadLocation.c_str(), "wb");
    if (!fp)
    {
        throw std::runtime_error("HTTP-Utility: Failed to create file on the disk");
    }

    auto* curl = _httpClient.getClient();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode responseCodeCurl = curl_easy_perform(curl);
    if (responseCodeCurl)
    {
        fclose(fp);
        throw std::runtime_error("HTTP-Utility: Failed to download URL " + url +
            "\nAssociated CURL code: " + std::to_string(responseCodeCurl));
    }

    long responseCodeHtml = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCodeHtml);
    if (responseCodeHtml != 200 && responseCodeHtml != 201)
    {
        fclose(fp);
        throw std::runtime_error("HTTP-Utility: Failed to download URL " + url +
            "\nAssociated HTTP code: " + std::to_string(responseCodeHtml));
    }

    fclose(fp);
    _debug.log("HTTP-Utility: Downloaded URL " + url + " to " + downloadLocation);
    return downloadLocation;
}

[[maybe_unused]] void Http::setDownloadDirectory(const std::string& directory) {
    _downloadDirectory = directory;
}

bool Http::isValidUrl(const std::string& url) {
    return std::regex_match (url.begin(), url.end(),
        std::regex {R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)", std::regex::extended});
}

std::string Http::extractFilenameFromUrl(const std::string& url) {
    std::smatch match;
    if (std::regex_search(url.begin(), url.end(), match, std::regex {"([^\\/]+$)"}))
        return match[0].str();
    throw std::runtime_error("HTTP-Utility: No filename found in URL: " + url);
}
