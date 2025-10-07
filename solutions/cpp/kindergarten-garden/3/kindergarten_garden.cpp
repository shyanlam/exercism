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

    std::array<Plants, 4> plants(const std::string& plant_assignment, const std::string& student) {
        const size_t row_break = plant_assignment.find("\n");
        assert(row_break != std::string::npos);
        const size_t row2_start = row_break + 1;
        std::string row[2] = {
            plant_assignment.substr(0, row_break),
            plant_assignment.substr(row_break + 1)
        };
        auto student_index = static_cast<size_t>(std::distance(STUDENTS.begin(), std::find(STUDENTS.begin(), STUDENTS.end(), student)));
        if (student_index == STUDENTS.size())
            throw std::domain_error("unknown student");
        
        auto plant_index = student_index * 2;
        if (plant_index >= row_break)
            throw std::domain_error("invalid argument value");

        return {
            static_cast<Plants>(plant_assignment[plant_index]), 
            static_cast<Plants>(plant_assignment[plant_index + 1]),
            static_cast<Plants>(plant_assignment[row2_start + plant_index]), 
            static_cast<Plants>(plant_assignment[row2_start + plant_index + 1])
        };
    }

}  // namespace kindergarten_garden
