#include "sublist.h"
#include <algorithm>
namespace sublist {

// TODO: add your solution here
    List_comparison sublist(const std::initializer_list<int>& list1, const std::initializer_list<int>& list2) {
        const size_t size1 = list1.size();
        const size_t size2 = list2.size();

        if (size1 == 0 && size2 == 0)
            return List_comparison::equal;

        if (size1 == size2)
            return std::equal(list1.begin(), list1.end(), list2.begin()) ? List_comparison::equal : List_comparison::unequal;
        else if (size1 > size2)
            return std::search(list1.begin(), list1.end(), list2.begin(), list2.end()) != list1.end() 
            ? List_comparison::superlist 
            : List_comparison::unequal;
        else
            return std::search(list2.begin(), list2.end(), list1.begin(), list1.end()) != list2.end() 
            ? List_comparison::sublist 
            : List_comparison::unequal;
    }
}  // namespace sublist
