#pragma once
#include <utility>
#include <string_view>
namespace robot_simulator {

// TODO: add your solution here
    enum class Bearing {
        NORTH,
        EAST,
        SOUTH,
        WEST,
    };
    class Robot {
    public:
        using position_t = std::pair<int, int>;

        Robot() = default;
        Robot(const position_t& start_pos, const Bearing bearing)
            : _x(start_pos.first)
            , _y(start_pos.second)
            , _bearing(bearing) {
        }

        position_t get_position() const { return { _x, _y }; }
        Bearing get_bearing() const { return _bearing; }

        void turn_right();
        void turn_left();
        void advance();

        void execute_sequence(const std::string_view sequence);

    private:
              int& x()       { return _x; }
        const int& x() const { return _x; }

              int& y()       { return _y; }
        const int& y() const { return _y; }

              Bearing& bearing()       { return _bearing; }
        const Bearing& bearing() const { return _bearing; }

    private:
        int _x{};
        int _y{};
        Bearing _bearing{ Bearing::NORTH };
    };

}  // namespace robot_simulator
