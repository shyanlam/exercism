#include "robot_simulator.h"
#include <cctype>
#include <type_traits>
namespace robot_simulator {

// TODO: add your solution here

    void Robot::turn_right() {
        switch (bearing()) {
        case Bearing::NORTH: bearing() = Bearing::EAST; break;
        case Bearing::EAST: bearing() = Bearing::SOUTH; break;
        case Bearing::SOUTH: bearing() = Bearing::WEST; break;
        case Bearing::WEST: bearing() = Bearing::NORTH; break;
        }
    }

    void Robot::turn_left() {
        switch (bearing()) {
        case Bearing::NORTH: bearing() = Bearing::WEST; break;
        case Bearing::EAST: bearing() = Bearing::NORTH; break;
        case Bearing::SOUTH: bearing() = Bearing::EAST; break;
        case Bearing::WEST: bearing() = Bearing::SOUTH; break;
        }
    }

    void Robot::advance() {
        switch (bearing()) {
        case Bearing::NORTH: ++position().second; break;
        case Bearing::EAST: ++position().first; break;
        case Bearing::SOUTH: --position().second; break;
        case Bearing::WEST: --position().first; break;
        }
    }

    void Robot::execute_sequence(const std::string_view sequence) {
        for (const auto& ch : sequence) {
            switch (std::toupper(ch)) {
            case 'L': turn_left(); break;
            case 'R': turn_right(); break;
            case 'A': advance(); break;
            }
        }
    }

}  // namespace robot_simulator
