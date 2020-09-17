#include <iostream>

#include "UnorderedArray.h"
#include "OrderedArray.h"

void testUnordered(int);

void testOrdered(int, bool);

using namespace std;

int main() {
    // Test unordered
    testUnordered(1);
    testUnordered(2);
    testUnordered(3);
    testUnordered(10);

    // Test ordered with duplicate
    testOrdered(1, false);
    testOrdered(2, false);
    testOrdered(3, false);
    testOrdered(10, false);

    // Test ordered without duplicate
    testOrdered(1, true);
    testOrdered(2, true);
    testOrdered(3, true);
    testOrdered(10, true);

    return 0;
}

void testUnordered(int size) {
    // Test unordered array
    cout << "Test unordered array with start size = " << size << endl;
    UnorderedArray<int> unorderedArray = UnorderedArray<int>(size);
    unorderedArray.push(1);
    cout << "Current array size is " << unorderedArray.GetSize() << ", max size is " << unorderedArray.GetMaxSize()
         << endl;
    unorderedArray.push(100);
    cout << "Current array size is " << unorderedArray.GetSize() << ", max size is " << unorderedArray.GetMaxSize()
         << endl;
    unorderedArray.push(10);
    cout << "Current array size is " << unorderedArray.GetSize() << ", max size is " << unorderedArray.GetMaxSize()
         << endl;
    unorderedArray.push(50);
    cout << "Current array size is " << unorderedArray.GetSize() << ", max size is " << unorderedArray.GetMaxSize()
         << endl;
    cout << endl;
}

void testOrdered(int size, bool prevent_duplicate) {
    // Test unordered array
    cout << "Test ordered array with start size = " << size << ", prevent_duplicate is " <<
         (prevent_duplicate ? "true" : "false") << endl;
    OrderedArray<int> orderedArray = OrderedArray<int>(size, prevent_duplicate);
    orderedArray.push(1);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;
    orderedArray.push(100);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;
    orderedArray.push(10);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;
    orderedArray.push(50);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;

    // Try to add duplicate
    orderedArray.push(10);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;
    orderedArray.push(50);
    cout << "Current array size is " << orderedArray.GetSize() << ", max size is " << orderedArray.GetMaxSize()
         << endl;

    cout << endl;
}
