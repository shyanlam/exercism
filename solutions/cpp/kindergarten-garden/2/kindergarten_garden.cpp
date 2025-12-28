#include "kindergarten_garden.h"
#include <algorithm>
#include <iterator>
#include <cassert>
#include <map>
#include <stdexcept>
#include <vector>
namespace kindergarten_garden {

// TODO: add your solution here

    const std::vector<std::string> STUDENTS{
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Eve",
        "Fred",
        "Ginny",
        "Harriet",
        "Ileana",
        "Joseph",
        "Kincaid",
        "Larry"
    };

    const std::map<char, Plants> PLANT_CODE{
        {'C', Plants::clover},
        {'G', Plants::grass},
        {'V', Plants::violets},
        {'R', Plants::radishes}
    };

    std::array<Plants, 4> plants(const std::string& plant_assignment, const std::string& student) {
        const size_t pos = plant_assignment.find("\n");
        assert(pos != std::string::npos);
        std::string row[2] = {
            plant_assignment.substr(0, pos),
            plant_assignment.substr(pos + 1)
        };
        auto student_index = static_cast<size_t>(std::distance(STUDENTS.begin(), std::find(STUDENTS.begin(), STUDENTS.end(), student)));
        if (student_index == STUDENTS.size())
            throw std::domain_error("unknown student");
        
        auto plant_index = student_index * 2;
        if (plant_index >= row[0].length() || plant_index >= row[1].length())
            throw std::domain_error("invalid argument value");

        return {
            PLANT_CODE.at(row[0][plant_index]), PLANT_CODE.at(row[0][plant_index + 1]),
            PLANT_CODE.at(row[1][plant_index]), PLANT_CODE.at(row[1][plant_index + 1])
        };
    }

}  // namespace kindergarten_garden
