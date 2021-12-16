#ifndef GOAT_ENGINE_HIGHSCOREKEEPER_HPP
#define GOAT_ENGINE_HIGHSCOREKEEPER_HPP

#include <map>
#include <vector>

class Script_LoadScoreboard; // Friend class link
/// Helper class to store highscores
class HighScoreKeeper {
    public:
        HighScoreKeeper() = delete;
    private:
        friend class Script_LoadScoreboard;

        explicit HighScoreKeeper(int topScoreCap);
        void addScore(unsigned int saveId, unsigned int score);
        [[nodiscard]] std::vector<std::pair<unsigned int, unsigned int>> getTopScores() const;

        std::map<unsigned int, unsigned int> _scores {};
        int _topScoreCap; // Used to get the correct amount of top scores
};

#endif //GOAT_ENGINE_HIGHSCOREKEEPER_HPP
