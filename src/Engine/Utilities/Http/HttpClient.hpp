#ifndef GOAT_ENGINE_HTTPCLIENT_HPP
#define GOAT_ENGINE_HTTPCLIENT_HPP

extern "C" {
    #include <curl.h>
}
#include <memory>
#include "../../NoCopyNoMove.hpp"

namespace Engine {
    class Http; // Friend class link
    /// Pimpl out CURL
    class HttpClient: NoCopyNoMove {
        public:
            void* getClient() const;
        private:
            friend class Engine::Http;
            HttpClient();
            std::unique_ptr<CURL,void(*)(CURL*)> _curl;
    };
}

#endif //GOAT_ENGINE_HTTPCLIENT_HPP
