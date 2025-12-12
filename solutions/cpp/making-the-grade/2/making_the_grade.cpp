#include <array>
#include <algorithm>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result{};
    for (auto s : student_scores) {
        result.push_back(static_cast<int>(s));
    }
    return result;
}

const int MIN_PASSING_SCORE = 40;
// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int failed = std::count_if(student_scores.begin(), student_scores.end(),
        [](int score) { return score <= MIN_PASSING_SCORE; });
    return failed;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int step = (highest_score - MIN_PASSING_SCORE) / 4;
    std::array<int, 4> result{};
    result[0] = MIN_PASSING_SCORE + 1;
    for (size_t n = 1; n < 4; ++n) {
        result[n] = result[n - 1] + step;
    }
    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result{};
    for (size_t n = 0; n < student_scores.size(); ++n) {
        result.push_back(std::to_string(n + 1) + ". " +
            student_names[n] + ": " + std::to_string(student_scores[n]));
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (size_t n = 0; n < student_scores.size(); ++n) {
        if (student_scores[n] == 100) {
            return student_names[n];
        }
    }
    return "";
}
