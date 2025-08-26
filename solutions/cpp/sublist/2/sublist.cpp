#include "sublist.h"
#include <algorithm>
#include <cassert>
namespace sublist {

// TODO: add your solution here
    bool match_rest(const std::vector<int>::const_iterator lgStart, const std::vector<int>::const_iterator lgEnd,
                    const std::vector<int>& smaller) {
        assert(*lgStart == smaller[0]);
        auto sm = smaller.begin();
        const auto smEnd = smaller.end();
        for (auto lg = lgStart; lg != lgEnd && sm != smEnd && *lg == *sm; ++lg, ++sm) {}
        return sm == smEnd;
    }
    bool is_sublist(const std::vector<int>& larger, const std::vector<int>& smaller) {
        assert(larger.size() > smaller.size());
        if (smaller.size() == 0)
            return true;

        const auto lgEnd = larger.end();
        const auto smStart = smaller.begin();
        const auto smEnd = smaller.end();
        for (auto lgStart = std::find(larger.begin(), lgEnd, *smStart); lgStart != lgEnd; ) {
            if (match_rest(lgStart, lgEnd, smaller))
                return true;

            lgStart = std::find(++lgStart, larger.end(), smaller[0]);
        }

        return false;
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
