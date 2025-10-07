#pragma once
#include <array>
#include <string>
namespace kindergarten_garden {

// TODO: add your solution here
    enum class Plants {
        clover,
        grass,
        violets,
        radishes
    };

    std::array<Plants, 4> plants(const std::string& plant_assignment, const std::string& student);
}  // namespace kindergarten_garden
