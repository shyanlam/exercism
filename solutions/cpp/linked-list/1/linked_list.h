#pragma once
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>
namespace linked_list {
// TODO: add your solution here
    template <typename T>
    class Node {
    public:
        Node(const T& value, std::shared_ptr<Node<T>> prev = nullptr, std::shared_ptr<Node<T>> next = nullptr)
            : _value(value)
            , _prev(prev)
            , _next(next)
        {
            //std::cerr << "\tConstructing: " << repr() << std::endl;
        }
        ~Node() {
            //std::cerr << "\tDestroy: " << repr() << std::endl;
        }
        
        friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<Node<T>>& ptr) {
            return (ptr ? os << ptr.get() : os << "nullptr");
        }
        std::string repr() const {
            std::stringstream ss;
            ss << "Node(this = " << this << ", value = " << _value
               << ", _prev = " << _prev
               << ", _next = " << _next
               << ")";
            return ss.str();
        }

        void unlink() {
            _prev = nullptr;
            _next = nullptr;
        }

              T& value()       { return _value; }
        const T& value() const { return _value; }

              std::shared_ptr<Node<T>>& prev()       { return _prev; }
        const std::shared_ptr<Node<T>>& prev() const { return _prev; }

              std::shared_ptr<Node<T>>& next()       { return _next; }
        const std::shared_ptr<Node<T>>& next() const { return _next; }

    private:
        T _value{};
        std::shared_ptr<Node<T>> _prev{};
        std::shared_ptr<Node<T>> _next{};
    };

    template <typename T>
    class List {
    public:
        List() = default;
        ~List();
        bool empty() const;
        void push(const T& value);
        T pop();
        T shift();
        void unshift(const T& value);
        size_t count() const;
        bool erase(const T& t);
        void erase(std::shared_ptr<Node<T>>& node);
        std::string repr() const;

    private:
        std::shared_ptr<Node<T>> _head{};
        std::shared_ptr<Node<T>> _tail{};
    };

    template <typename T>
    List<T>::~List() {
        std::shared_ptr<Node<T>> cur = _head;
        while (cur != nullptr) {
            std::shared_ptr<Node<T>> tmp = cur;
            //std::cerr << "\t~List: " << cur->repr() << std::endl;
            cur = cur->next();
            _head = cur;
            tmp->unlink();
        }
    }

    template <typename T>
    bool List<T>::empty() const {
        assert(static_cast<bool>(_head) == static_cast<bool>(_tail));
        return _head == nullptr;
    }

    template <typename T>
    std::string List<T>::repr() const {
        std::ostringstream ss;
        ss << "List: ";
        if (_head == nullptr) {
            assert(_tail == nullptr);
            ss << "\tempty." << std::endl;
        } else {
            ss << "\t_head = " << _head << std::endl;
            auto cur = _head;
            while (cur != nullptr) {
                ss << "\t" << cur->repr() << std::endl;
                cur = cur->next();
            }
            ss << "\t_tail = " << _tail << std::endl;
        }
        return ss.str();
    }

    template <typename T>
    size_t List<T>::count() const {
        size_t count{ 0 };
        for (auto cur = _head; cur != nullptr; cur = cur->next(), ++count) {
            auto str = cur->repr();
        }
        return count;
    }

    template <typename T> 
    void List<T>::push(const T& value) {
        // add to tail
        if (!_tail) {
            assert(_head == nullptr);
            auto node = std::make_shared<Node<T>>(value);
            _head = _tail = node;
        } else {
            assert(_head);
            auto last = _tail;
            auto node = std::make_shared<Node<T>>(value, _tail, nullptr);
            _tail->next() = node;
            _tail = node;
        }
    }

    template <typename T>
    T List<T>::pop() {
        // return last value and remove last node
        auto cur = _tail;
        if (_tail && _tail == _head) {
            // one node
            assert(cur->prev() == nullptr && cur->next() == nullptr);
            _tail = _head = nullptr;
        } else {
            assert(cur->prev());
            _tail = cur->prev();
            _tail->next() = nullptr;
        }
        cur->unlink();
        return cur->value();
    }

    template <typename T>
    T List<T>::shift() {
        // return first value and remove firest node
        auto cur = _head;
        if (_head && _head == _tail) {
            // one node
            assert(cur->prev() == nullptr && cur->next() == nullptr);
            _head = _tail = nullptr;
        } else {
            assert(cur->next());
            _head = cur->next();
            _head->prev() = nullptr;
        }
        cur->unlink();
        return cur->value();
    }

    template <typename T>
    void List<T>::unshift(const T& value) {
        // add to front
        if (!_head) {
            assert(!_tail);
            auto node = std::make_shared<Node<T>>(value);
            _head = _tail = node;
        } else {
            assert(_tail);
            auto node = std::make_shared<Node<T>>(value, nullptr, _head);
            _head->prev() = node;
            _head = node;
        }
    }

    template <typename T>
    void List<T>::erase(std::shared_ptr<Node<T>>& ptr) {
        auto prev = ptr->prev();
        auto next = ptr->next();
        if (prev) {
            prev->next() = next;
        }
        if (next) {
            next->prev() = prev;
        }
        if (_head == ptr) {
            _head = next;
        }
        if (_tail == ptr) {
            _tail = prev;
        }
        ptr->unlink();
    }
    template <typename T>
    bool List<T>::erase(const T& value) {
        //std::cerr << std::endl << repr() << std::endl;
        for (auto cur = _head; cur; cur = cur->next()) {
            if (cur->value() == value) {
                erase(cur);
                return true;
            }
        }
        return false;
    }
}  // namespace linked_list
