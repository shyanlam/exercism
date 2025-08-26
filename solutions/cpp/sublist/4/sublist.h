#pragma once
#include <initializer_list>
namespace sublist {

// TODO: add your solution here
    enum class List_comparison {
        equal,
        sublist,
        superlist,
        unequal,
    };
    List_comparison sublist(const std::initializer_list<int>& list1, const std::initializer_list<int>& list2);
}  // namespace sublist
