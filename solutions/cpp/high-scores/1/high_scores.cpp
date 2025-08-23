#include "high_scores.h"
#include <algorithm>
#include <functional>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    std::vector<int> result(std::min<size_t>(3, scores.size()));
    std::partial_sort_copy(scores.begin(), scores.end(), result.begin(), result.end(), std::greater<int>());
    return result;
}

}  // namespace arcade
