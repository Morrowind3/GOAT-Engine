#ifndef GOAT_ENGINE_HTTP_HPP
#define GOAT_ENGINE_HTTP_HPP

#include <vector>
#include <regex>
#include "Http/HttpClient.hpp"
#include "Debug.hpp"

namespace Engine {
    class Http {
        public:
            Http(Http const&) = delete;
            void operator=(Http const&) = delete;
            static Http& getInstance() {
                static Http instance;
                return instance;
            }
            [[maybe_unused]] void setDownloadDirectory(const std::string& directory);
            [[nodiscard]] std::string downloadFromWeb(const std::string& url) const;

        private:
            Http() = default;
            // Utilities
            Debug& _debug = Debug::getInstance();
            // Variables
            HttpClient _httpClient {};
            std::string _downloadDirectory {".\\Web\\"};
            // Methods
            static bool isValidUrl(const std::string& url);
            static std::string extractFilenameFromUrl(const std::string& url);
    };
}

#endif //GOAT_ENGINE_HTTP_HPP
