#include <algorithm>
#include "HighScoreKeeper.hpp"

HighScoreKeeper::HighScoreKeeper(const int topScoreCap) : _topScoreCap{topScoreCap} {
}

void HighScoreKeeper::addScore(const unsigned int saveId, const unsigned int score) {
    auto entry = _scores.find(saveId);
    if (entry == _scores.end()) _scores.insert(std::make_pair(saveId,score));
    else entry->second += score;
}

std::vector<std::pair<unsigned int, unsigned int>> HighScoreKeeper::getTopScores() const {
    // Copy all scores to a sortable vector
    std::vector<std::pair<unsigned int, unsigned int>> sortableScores {};
    for (auto& score: _scores) sortableScores.emplace_back(score);

    // Sort by descending score
    auto sort = [](const std::pair<unsigned int,unsigned int>& a, const std::pair<unsigned int,unsigned int>& b)
    {
        return a.second > b.second;
    };
    std::sort(sortableScores.begin(), sortableScores.end(), sort);

    // Return only the top scores
    return std::vector<std::pair<unsigned int, unsigned int>>
        { sortableScores.begin(), sortableScores.begin()+_topScoreCap };
}
