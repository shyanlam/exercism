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

        Robot(const position_t& pos_start = {0, 0}, const Bearing bearing = Bearing::NORTH)
            : _position(pos_start)
            , _bearing(bearing) {
        }

        position_t get_position() const { return _position; }
        Bearing get_bearing() const { return _bearing; }

        void turn_right();
        void turn_left();
        void advance();

        void execute_sequence(const std::string_view sequence);

    private:
        position_t& position() { return _position; }
        const position_t& position() const { return _position; }

        Bearing& bearing() { return _bearing; }
        const Bearing& bearing() const { return _bearing; }

    private:
        position_t _position{};
        Bearing _bearing{ Bearing::NORTH };
    };

}  // namespace robot_simulator
