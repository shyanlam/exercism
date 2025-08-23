#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    size_t count{ 0 };
    for (auto cur = head.get(); cur; cur = cur->next.get(), ++count) {
        auto r = cur->repr();
    }
    return count;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    head = std::unique_ptr<Element>(new Element{ entry, std::move(head) });
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    auto cur = std::move(head);
    head = std::move(cur->next);
    return cur->data;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.

    std::unique_ptr<Element> prev{}, next{};
    auto cur = std::move(head);
    while (cur) {
        next = std::move(cur->next);
        cur->next = std::move(prev);
        prev = std::move(cur);
        cur = std::move(next);
    }
    head = std::move(prev);
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while (head) {
        head = std::move(head->next);
    }
}

}  // namespace simple_linked_list
