#include "sublist.h"
#include <algorithm>
#include <cassert>
namespace sublist {

// TODO: add your solution here
    bool is_sublist(const std::vector<int>& larger, const std::vector<int>& smaller) {
        assert(larger.size() > smaller.size());
        if (smaller.size() == 0)
            return true;

        return std::search(larger.begin(), larger.end(), smaller.begin(), smaller.end()) != larger.end();
    }
    List_comparison sublist(const std::vector<int>& list1, const std::vector<int>& list2) {
        if (list1 == list2) {
            return List_comparison::equal;
        }
        if (list1.size() == list2.size())
            return List_comparison::unequal;

        if (list1.size() > list2.size()) {
            if (is_sublist(list1, list2))
                return List_comparison::superlist;
        } else if (list1.size() < list2.size()) {
            if (is_sublist(list2, list1))
                return List_comparison::sublist;
        }
        return List_comparison::unequal;
    }
}  // namespace sublist
