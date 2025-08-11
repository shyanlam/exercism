#pragma once

namespace perfect_numbers {
    enum class classification {
        perfect,
        abundant,
        deficient
    };
    classification classify(long long value);
}  // namespace perfect_numbers
