#ifndef GOAT_ENGINE_NOCOPYNOMOVE_HPP
#define GOAT_ENGINE_NOCOPYNOMOVE_HPP

class NoCopyNoMove {
    public:
        NoCopyNoMove(const NoCopyNoMove&) = delete;
        NoCopyNoMove& operator=(const NoCopyNoMove&) = delete;
        NoCopyNoMove(NoCopyNoMove&&) = delete;
        NoCopyNoMove& operator=(NoCopyNoMove&&) = delete;
        virtual ~NoCopyNoMove() = default;
    protected:
        NoCopyNoMove() = default;
};

#endif //GOAT_ENGINE_NOCOPYNOMOVE_HPP
