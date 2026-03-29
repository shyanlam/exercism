#pragma once

#include <cstddef>
//#include <iostream>
#include <memory>
#include <string>
#include <sstream>
namespace simple_linked_list {

class List {
   public:
    List() = default;
    ~List();

    // Moving and copying is not needed to solve the exercise.
    // If you want to change these, make sure to correctly
    // free / move / copy the allocated resources.
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;

    std::size_t size() const;
    void push(int entry);
    int pop();
    void reverse();

    std::string repr() const {
        std::ostringstream ss;
        ss << "List: ";
        if (!head) {
            ss << "\tempty." << std::endl;
        } else {
            ss << "\thead = " << head << std::endl;
            auto cur = head.get();
            while (cur) {
                ss << "\t" << cur->repr() << std::endl;
                cur = cur->next.get();
            }
        }
        return ss.str();
    }


   private:
    struct Element {
        Element(int data, std::unique_ptr<Element> _next = nullptr) 
            : data{data}
            , next(std::move(_next)) {
            //std::cerr << "\tConstructing: " << repr() << std::endl;
        };
        ~Element() {
            //std::cerr << "\tDestroy: " << repr() << std::endl;
        }
        int data{};
        std::unique_ptr<Element> next{nullptr};

        friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<Element>& ptr) {
            return (ptr ? os << ptr.get() : os << "nullptr");
        }
        std::string repr() const {
            std::ostringstream ss;
            ss << "Node(this = " << this
                << ", data = " << data
                << ", next = " << next
                << ")";
            return ss.str();
        }
    };

    std::unique_ptr<Element> head{nullptr};
    std::size_t current_size{0};
};

}  // namespace simple_linked_list
