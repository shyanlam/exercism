#pragma once
#include <array>
#include <string>
namespace kindergarten_garden {

// TODO: add your solution here
    enum class Plants : char {
        clover = 'C',
        grass = 'G',
        violets = 'V',
        radishes = 'R'
    };

    std::array<Plants, 4> plants(const std::string& plant_assignment, const std::string& student);
}  // namespace kindergarten_garden
