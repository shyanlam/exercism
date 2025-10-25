#include "twelve_days.h"
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <vector>
namespace twelve_days {

// TODO: add your solution here

    const std::vector<std::string> Nth = {
        "",
        " first ", " second ", " third ", " fourth ", " fifth ", " sixth ",
        " seventh ", " eighth ", " ninth ", " tenth ", " eleventh ", " twelfth "
    };

    const std::vector<std::string> present = {
        "",
        " a Partridge in a Pear Tree.",
        " two Turtle Doves,",
        " three French Hens,",
        " four Calling Birds,",
        " five Gold Rings,",
        " six Geese-a-Laying,",
        " seven Swans-a-Swimming,",
        " eight Maids-a-Milking,",
        " nine Ladies Dancing,",
        " ten Lords-a-Leaping,",
        " eleven Pipers Piping,",
        " twelve Drummers Drumming,"
    };

    bool in_range(int day) {
        return 0 < day && static_cast<size_t>(day) < Nth.size();
    }

    std::string recite(int day) {
        assert(in_range(day));
        std::stringstream ss;
        ss << "On the" << Nth[day] << "day of Christmas my true love gave to me:";
        for (; 0 < day; --day) {
            ss << present[day];
            if (day == 2)
                ss << " and";
        }
        ss << std::endl;
        return ss.str();
    }

    std::string recite(int start, int last) {
        if (!in_range(start) || !in_range(last))
            throw std::out_of_range("day out of range.");

        std::stringstream ss;
        for (int day = start; day <= last; ++day) {
            if (!ss.str().empty())
                ss << std::endl;
            ss << recite(day);
        }
        return ss.str();
    }
}  // namespace twelve_days
