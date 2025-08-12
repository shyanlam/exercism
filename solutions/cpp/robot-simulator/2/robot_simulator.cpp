#include "robot_simulator.h"
#include <cctype>
#include <type_traits>
namespace robot_simulator {

// TODO: add your solution here

    void Robot::turn_right() {
        const int b = static_cast<int>(bearing());
        bearing() = static_cast<Bearing>((b + 1) % 4);
    }

    void Robot::turn_left() {
        const int b = static_cast<int>(bearing());
        bearing() = static_cast<Bearing>((b - 1 + 4) % 4);
    }

    void Robot::advance() {
        switch (bearing()) {
        case Bearing::NORTH: ++y(); break;
        case Bearing::EAST: ++x(); break;
        case Bearing::SOUTH: --y(); break;
        case Bearing::WEST: --x(); break;
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
