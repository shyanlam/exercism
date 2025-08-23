#include "eliuds_eggs.h"

namespace chicken_coop {

// TODO: add your solution here
    int positions_to_quantity(unsigned long long positions) {
        int count{ 0 };
        for (; positions;  positions &= (positions - 1)) {
            ++count;
        }
        return count;
    }

}  // namespace chicken_coop
