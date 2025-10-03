#pragma once
#include <vector>

namespace list_ops {

// TODO: add your solution here
    // append
    template <typename T, template<typename...> typename Coll>
    void append(Coll<T>& left, const Coll<T>& right) {
        for (auto& value : right) {
            left.push_back(value);
        }
    }

    // concat
    template <typename T> 
    std::vector<T> concat(const std::vector<std::vector<T>>& input) {
        std::vector<T> result;
        for (auto& vv : input) {
            for (auto& v : vv) {
                result.push_back(v);
            }
        }
        return result;
    }

    // filter
    template <typename T, template<typename...> typename Coll, typename UnaryPred>
    Coll<T> filter(const Coll<T>& input, UnaryPred p) {
        Coll<T> result{};
        for (const auto& v : input) {
            if (p(v))
                result.push_back(v);
        }
        return result;
    }

    // length
    template <typename T, template<typename...> typename Coll>
    size_t length(const Coll<T>& input) {
        return input.size();
    }

    // map
    template <typename T, template<typename...> typename Coll, typename UnaryFunc>
    Coll<T> map(const Coll<T>& input, UnaryFunc f) {
        Coll<T> result{};
        for (auto& v : input) {
            result.push_back(f(v));
        }
        return result;
    }

    // foldl
    template <typename T, typename BinaryFunc>
    T foldl(const std::vector<T>& input, const T& acc, BinaryFunc f) {
        T result{ acc };
        for (auto& v : input) {
            result = f(result, v);
        }
        return result;
    }

    // foldr
    template <typename T, typename BinaryFunc>
    T foldr(const std::vector<T>& input, const T& acc, BinaryFunc f) {
        T result{ acc };
        for (auto rit = std::rbegin(input); rit != std::rend(input); ++rit) {
            result = f(result, *rit);
        }
        return result;
    }

    // reverse
    template <typename T, template<typename...> typename Coll>
    Coll<T> reverse(const Coll<T>& input) {
        Coll<T> result{};
        for (auto rit = std::rbegin(input); rit != std::rend(input); ++rit) {
            result.push_back(*rit);
        }
        return result;
    }

}  // namespace list_ops
