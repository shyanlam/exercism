#pragma once
#include <map>
#include <vector>
namespace etl {

// TODO: add your solution here
    using point_to_letter_t = std::map<int, std::vector<char>>;
    using letter_to_point_t = std::map<char, int>;

    letter_to_point_t transform(const point_to_letter_t& old);  
}  // namespace etl
