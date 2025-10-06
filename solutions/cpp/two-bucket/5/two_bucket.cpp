#include "two_bucket.h"
#include <cassert>
#include <stdexcept>
#include <numeric>

namespace two_bucket {

    // TODO: add your solution here
    class bucket_t {
    public:
        bucket_t(int capacity, bucket_id id) : _capacity(capacity), _id(id) {}
        const auto volume() const { return _volume; }
        auto& volume() { return _volume; }
        auto capacity() const { return _capacity; }
        auto id() const { return _id; }

        auto is_full() const { return _volume == _capacity; }
        auto is_empty() const { return _volume == 0; }
        void fill(int& num_moves) { _volume = _capacity; ++num_moves; }
        void empty(int& num_moves) { _volume = 0; ++num_moves; }

    private:
        bucket_id _id{};
        int _volume{ 0 };
        int _capacity{ 0 };
    };

    auto pour(bucket_t& from, bucket_t& to, int target_volume, measure_result& result) {
        if (auto amount = std::min(from.volume(), to.capacity() - to.volume()); amount > 0) {
            from.volume() -= amount;
            to.volume() += amount;
            ++result.num_moves;
        }
        if (from.volume() == target_volume) {
            result.goal_bucket = from.id();
            result.other_bucket_volume = to.volume();
            return true;
        } else if (to.volume() == target_volume) {
            result.goal_bucket = to.id();
            result.other_bucket_volume = from.volume();
            return true;
        }
        return false;
    }

    void check_rule3(const bucket_t& start, const bucket_t& other) {
        if (start.is_empty() && other.is_full())
            throw std::runtime_error("rule3 violation");
    }

    measure_result measure(int bucket1_capacity, int bucket2_capacity, int target_volume, bucket_id start_bucket) {
        if (bucket1_capacity < target_volume && bucket2_capacity < target_volume)
            throw std::runtime_error("no solution");

        if ((target_volume % std::gcd(bucket1_capacity, bucket2_capacity)) != 0)
            throw std::runtime_error("no solution");

        bucket_t bucket1(bucket1_capacity, bucket_id::one), bucket2(bucket2_capacity, bucket_id::two);
        bucket_id other_bucket = start_bucket == bucket_id::one ? bucket_id::two : bucket_id::one;
        bucket_t& start = start_bucket == bucket_id::one ? bucket1 : bucket2;
        bucket_t& other = other_bucket == bucket_id::one ? bucket1 : bucket2;

        if (start.capacity() == target_volume) 
            return measure_result{ 1, start_bucket, 0 };
        if (other.capacity() == target_volume) 
            return measure_result{ 2, other_bucket, start.capacity() };
        
        measure_result result{};
        start.fill(result.num_moves);
        do {
            if (pour(start, other, target_volume, result)) {
                check_rule3(start, other);
                return result;
            }

            if (other.is_full()) {
                other.empty(result.num_moves);
            }

            if (start.is_empty()) {
                start.fill(result.num_moves);
            }
        } while (!(start.is_full() && other.is_empty()));

        assert(false);
        throw std::runtime_error("no solution");
    }

    //measure_result measure(int bucket1_capacity, int bucket2_capacity, int target_volume, bucket_id start_bucket) {
    //    if (bucket1_capacity < target_volume && bucket2_capacity < target_volume)
    //        throw std::runtime_error("impossible target_volume");

    //    if ((target_volume % std::gcd(bucket1_capacity, bucket2_capacity)) != 0)
    //        throw std::runtime_error("No solution");

    //    using bucket_t = std::pair<int, int>; // volume, capacity
    //    measure_result result{};

    //    auto is_full = [](const bucket_t& bucket) -> bool { return bucket.first == bucket.second; };
    //    auto is_empty = [](const bucket_t& bucket) -> bool {return bucket.first == 0; };
    //    auto rule3 = [is_full, is_empty](const bucket_t& start, const bucket_t& other) {
    //        if (is_empty(start) && is_full(other))
    //            throw std::runtime_error("rule3 violation");
    //        };

    //    auto fill = [&result](bucket_t& bucket) {
    //        bucket.first = bucket.second;
    //        ++result.num_moves;
    //        };
    //    auto empty = [&result](bucket_t& bucket) {
    //        bucket.first = 0;
    //        ++result.num_moves;
    //        };
    //    auto pour = [&result, is_full, is_empty](bucket_t& from, bucket_t& to) {
    //        assert(!is_empty(from) && !is_full(to));
    //        auto amount = std::min(from.first, to.second - to.first);
    //        from.first -= amount;
    //        to.first += amount;
    //        ++result.num_moves;
    //        };
    //    auto goal_reached = [target_volume, &result](const bucket_t& bucket1, const bucket_t& bucket2) -> bool {
    //        if (bucket1.first == target_volume) {
    //            result.goal_bucket = bucket_id::one;
    //            result.other_bucket_volume = bucket2.first;
    //            return true;
    //        } else if (bucket2.first == target_volume) {
    //            result.goal_bucket = bucket_id::two;
    //            result.other_bucket_volume = bucket1.first;
    //            return true;
    //        }
    //        return false;
    //        };

    //    bucket_id other_bucket = start_bucket == bucket_id::one ? bucket_id::two : bucket_id::one;
    //    bucket_t bucket1{ 0, bucket1_capacity }, bucket2{ 0, bucket2_capacity };
    //    bucket_t& start = start_bucket == bucket_id::one ? bucket1 : bucket2;
    //    bucket_t& other = other_bucket == bucket_id::one ? bucket1 : bucket2;

    //    // fill start
    //    start.first = start.second;  ++result.num_moves;
    //    if (start.first == target_volume) {
    //        result.goal_bucket = start_bucket;
    //        result.other_bucket_volume = other.first;
    //        return result;
    //    } else if (other.second == target_volume) {
    //        ++result.num_moves;
    //        result.goal_bucket = other_bucket;
    //        result.other_bucket_volume = start.first;
    //        return result;
    //    } else {
    //        do {
    //            pour(start, other);
    //            rule3(start, other);
    //            if (goal_reached(bucket1, bucket2))
    //                return result;
    //            if (is_full(other)) {
    //                empty(other);
    //                if (goal_reached(bucket1, bucket2))
    //                    return result;
    //            }
    //            if (is_empty(start)) {
    //                fill(start);
    //                if (goal_reached(bucket1, bucket2))
    //                    return result;
    //            }
    //        } while (!(is_full(start) && is_empty(other)));
    //        // no solution
    //        assert(false);
    //        throw std::runtime_error("exhaused");
    //    }
    //}
}  // namespace two_bucket
