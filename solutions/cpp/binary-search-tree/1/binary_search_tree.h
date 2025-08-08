#pragma once
#include <iterator>
#include <memory>
#include <stack>
#include <string>
#include <vector>
namespace binary_search_tree {

// TODO: add your solution here

    template <typename T> class iterator_t;

    template <typename T>
    class binary_tree {
    public:
        using btree_t = binary_tree<T>;

        binary_tree(const T& data, binary_tree* parent = nullptr)
            : _data(data)
            , _parent(parent)
        { }

        T&       data()       { return _data; }
        const T& data() const { return _data;  }

              std::unique_ptr<btree_t>& left()       { return _left; }
        const std::unique_ptr<btree_t>& left() const { return _left; }

              std::unique_ptr<btree_t>& right()       { return _right; }
        const std::unique_ptr<btree_t>& right() const { return _right; }

        //btree_t*       parent()       { return _parent; }
        //const btree_t* parent() const { return _parent; }

        void insert(const T& new_value) {
            if (new_value <= data()) {
                if (left())
                    left()->insert(new_value);
                else
                    left() = std::make_unique<btree_t>(new_value, this);
            } else {
                if (right())
                    right()->insert(new_value);
                else
                    right() = std::make_unique<btree_t>(new_value, this);
            }
        }

        static binary_tree<T>* leftmost_node(binary_tree* pnode) {
            while (pnode && pnode->left()) {
                pnode = pnode->left().get();
            }
            return pnode;
        }
        binary_tree<T>* leftmost_node() {
            return leftmost_node(this);
        }

        using iterator_t = iterator_t<T>;
        using const_iterator_t = const iterator_t;
        friend iterator_t;

        iterator_t begin() {
            return iterator_t(leftmost_node(this));
        }
        iterator_t end() { return iterator_t{nullptr}; }

    private:
        T _data{};
        binary_tree* _parent{ nullptr };
        std::unique_ptr<btree_t> _left{};
        std::unique_ptr<btree_t> _right{};
    };

    template <typename T>
    class iterator_t {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = binary_tree<T>;
        using difference_type = void;
        using pointer = binary_tree<T>*;
        using reference = binary_tree<T>&;

        iterator_t() = default;
        iterator_t(binary_tree<T>* p) : current(p) {}
        T& operator*() { return current->data(); }
        iterator_t& operator++() {
            if (!current)
                return *this;
            if (current->right()) {
                current = binary_tree<T>::leftmost_node(current->right().get());
            } else {
                auto parent = current->_parent;
                while (parent && current == parent->right().get()) {
                    current = parent;
                    parent = parent->_parent;
                }
                current = parent;
            }
            return *this;
        }

        template <typename T>
        friend bool operator==(const iterator_t<T>& lhs, const iterator_t<T>& rhs);

        template <typename T>
        friend bool operator!=(const iterator_t<T>& lhs, const iterator_t<T>& rhs);
    private:
        binary_tree<T>* current{};
    };

    template <typename T>
    bool operator==(const iterator_t<T>& lhs, const iterator_t<T>& rhs) {
        return lhs.current == rhs.current;
    }
    template <typename T>
    bool operator!=(const iterator_t<T>& lhs, const iterator_t<T>& rhs) {
        return lhs.current != rhs.current;
    }


}  // namespace binary_search_tree
