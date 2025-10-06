#include "two_bucket.h"
#include <cassert>
#include <exception>
#include <numeric>

namespace two_bucket {

    // TODO: add your solution here

    measure_result measure(int bucket1_capacity, int bucket2_capacity, int target_volume, bucket_id start_bucket) {
        if (bucket1_capacity < target_volume && bucket2_capacity < target_volume)
            throw std::exception("impossible target_volume");

        if ((target_volume % std::gcd(bucket1_capacity, bucket2_capacity)) != 0)
            throw std::exception("No solution");

        using bucket_t = std::pair<int, int>; // volume, capacity
        measure_result result{};

        auto is_full = [](const bucket_t& bucket) -> bool { return bucket.first == bucket.second; };
        auto is_empty = [](const bucket_t& bucket) -> bool {return bucket.first == 0; };
        auto rule3 = [is_full, is_empty](const bucket_t& start, const bucket_t& other) {
            if (is_empty(start) && is_full(other))
                throw std::exception("rule3 violation");
            };

        auto fill = [&result](bucket_t& bucket) {
            bucket.first = bucket.second;
            ++result.num_moves;
            };
        auto empty = [&result](bucket_t& bucket) {
            bucket.first = 0;
            ++result.num_moves;
            };
        auto pour = [&result, is_full, is_empty](bucket_t& from, bucket_t& to) {
            assert(!is_empty(from) && !is_full(to));
            auto to_room = to.second - to.first;
            to.first = std::min(to.first + from.first, to.second);
            from.first = std::max(from.first - to_room, 0);
            ++result.num_moves;
            };
        auto goal_reached = [target_volume, &result](const bucket_t& bucket1, const bucket_t& bucket2) -> bool {
            if (bucket1.first == target_volume) {
                result.goal_bucket = bucket_id::one;
                result.other_bucket_volume = bucket2.first;
                return true;
            } else if (bucket2.first == target_volume) {
                result.goal_bucket = bucket_id::two;
                result.other_bucket_volume = bucket1.first;
                return true;
            }
            return false;
            };

        bucket_id other_bucket = start_bucket == bucket_id::one ? bucket_id::two : bucket_id::one;
        bucket_t bucket1{ 0, bucket1_capacity }, bucket2{ 0, bucket2_capacity };
        bucket_t& start = start_bucket == bucket_id::one ? bucket1 : bucket2;
        bucket_t& other = other_bucket == bucket_id::one ? bucket1 : bucket2;

        // fill start
        start.first = start.second;  ++result.num_moves;
        if (start.first == target_volume) {
            result.goal_bucket = start_bucket;
            result.other_bucket_volume = other.first;
            return result;
        } else if (other.second == target_volume) {
            ++result.num_moves;
            result.goal_bucket = other_bucket;
            result.other_bucket_volume = start.first;
            return result;
        } else {
            do {
                pour(start, other);
                if (goal_reached(bucket1, bucket2))
                    return result;
                if (is_full(other)) {
                    empty(other);
                    if (goal_reached(bucket1, bucket2))
                        return result;
                }
                if (is_empty(start)) {
                    fill(start);
                    if (goal_reached(bucket1, bucket2))
                        return result;
                }
            } while (!(is_full(start) && is_empty(other)));
            // no solution
            assert(false);
            throw std::exception("exhaused");
        }
    }
}  // namespace two_bucket
