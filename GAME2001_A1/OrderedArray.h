#pragma once

#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array<T> {
public:
    // Constructor
    OrderedArray(int size, bool prevent_duplicate = false) : Array<T>(size) {
        this->prevent_duplicate = prevent_duplicate;
    }

    // Destructor
    ~OrderedArray() {
    }

    // Insertion - Big O = O(N)
    /**
     * Push value to array
     * @param val Value to push to array
     * @return 1 - if value pushed, 0 - if failed to push value (duplicate and prevent_duplicate set to true)
     */
    int push(T val) {
        assert(this->m_array != NULL);

        int i, k;
        if (this->m_numElements >= this->m_maxSize) {
            // If prevent_duplicate set to true, check if we don't have such val

            for (i = 0; i < this->m_numElements; i++) {
                if (prevent_duplicate) {
                    if (this->m_array[i] == val)
                        return 0;
                }
            }
            this->Expand();
        }

        // Step 1: Find the index to insert val
        for (i = 0; i < this->m_numElements; i++) {
            // If prevent_duplicate set to true, check if we don't have such val
            if (prevent_duplicate) {
                if (this->m_array[i] == val)
                    return 0;
            }

            if (this->m_array[i] > val) {
                break;
            }
        }

        // Step 2: Shift everything to the right of the index forward by one
        for (k = this->m_numElements; k > i; k--)    // Moving backwards through the array starting at m_numElements
        {
            this->m_array[k] = this->m_array[k - 1];
        }

        // Step 3: Insert val into index
        this->m_array[i] = val;

        this->m_numElements++;

        return i;
    }

private:
    // Variables
    bool prevent_duplicate;
};