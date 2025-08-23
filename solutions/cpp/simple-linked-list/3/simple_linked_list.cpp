#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    head = new Element{ entry, head };
    ++current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    --current_size;
    auto cur = head;
    head = head->next;
    auto result = cur->data;
    delete cur;
    return result;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.

    Element* prev{}, *next{};
    auto cur = head;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    current_size = 0;
    while (head) {
        auto cur = head;
        head = head->next;
        delete cur;
    }
}

}  // namespace simple_linked_list
