#pragma once

#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T> {
public:
    // Constructor
    UnorderedArray(int size) : Array<T>(size) {
    }

    // Destructor
    ~UnorderedArray() {
    }

    // Insertions
    // Fast insertion for UnorderedArray -- Big-O is O(1)
    void push(T val) {
        assert(this->m_array != NULL);    // Debugging purposes

        if (this->m_numElements >= this->m_maxSize) {
            this->Expand();
        }

        // My array has space for the new value
        this->m_array[this->m_numElements] = val;
        this->m_numElements++;
    }
};