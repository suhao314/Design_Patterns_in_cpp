#pragma once
#include <iterator>         // For std::forward_iterator_tag
#include <cstddef>          // For std::ptrdiff_t

#define N 17

class Integers{
private:
    int m_data[N];

public:
    struct Iterator {
        /**
         * @brief Tag
         * Tags are used to select the most efficient algorithm if your container is passed to one of the Standard Library functions from the <algorithm> library.
         * The iterator category is also used to set algorithm requirements.
         *      i.e. std::fill wants a Forward Iterator while std::reverse wants a Bidirectional Iterator.
         */
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = value_type*;      /* or also int* */
        using reference         = value_type&;      /* or also int& */

        /* Iterator Constructor */
        Iterator(pointer ptr) : m_ptr(ptr) {}
        /* Operators Implementation */
        reference operator*() const {return *m_ptr; }
        pointer operator->() {return m_ptr; }
        Iterator& operator++() {m_ptr++; return *this; }                                /* Prefix increment */
        Iterator operator++(int) {Iterator tmp = *this; ++(*this); return tmp; }       /* Postfix increment */
        friend bool operator==(const Iterator& a, const Iterator& b) {return a.m_ptr == b.m_ptr; }
        friend bool operator!=(const Iterator& a, const Iterator& b) {return a.m_ptr != b.m_ptr; }
    private:
        pointer m_ptr;
    };

    Iterator begin() {return Iterator(m_data); }
    Iterator end() {return Iterator(&m_data[N]); }

};


/**
 * 6 Iterator Categories
 *  Input Iterator:             Can scan the container forward only once, can't change the value it points to (read-only);
 *  Output Iterator:            Can scan the container forward only once, can't read the value it points to (write-only);
 *  Forward Iterator:           Can scan the container forward multiple times, can read and write the value it points to;
 *  Bidirectional Iterator:     Same as previous one but can scan the container back and forth;
 *  Random Access Iterator:     Same as previous one but can access the container also non-sequentially (i.e. by jumping around);
 *  Contiguous Iterator:        Same as previous one, with the addition that logically adjacent elements are also physically adjacent in memory.
 * 
 * The six categories are hierarchical: a Bidirectional Iterator is also a Forward Iterator and a Random Access Iterator is both a Bidirectional and a Forward Iterator and so on.
 * 
 * 
 */