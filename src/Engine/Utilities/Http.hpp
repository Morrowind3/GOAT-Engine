#ifndef GOAT_ENGINE_HTTP_HPP
#define GOAT_ENGINE_HTTP_HPP


class Http {
public:
    Http(Http const&) = delete;
    void operator=(Http const&) = delete;
    static Http& getInstance() {
        static Http instance;
        return instance;
    }
private:
    Http()= default;
};


#endif //GOAT_ENGINE_HTTP_HPP
