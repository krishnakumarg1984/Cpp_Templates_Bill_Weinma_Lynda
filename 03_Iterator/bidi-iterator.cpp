// bidi-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-19 for CppSTL
#include <iostream>
#include <set>
using namespace std;

// The .end() function returns past the end, whilst .begin() returns an iterator
// right at the beginning

int main() {
    set<int> set1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    set<int>::iterator it1;  // iterator object

    // iterate forward
    for (it1 = set1.begin(); it1 != set1.end(); ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    // iterate backward
    for (it1 = set1.end(); it1 != set1.begin();) {
        // The .end() function returns past the end, whilst .begin() returns an
        // iterator right at the beginning. Hence, we need the decrement
        // operator here.
        cout << *--it1 << " ";
    }
    cout << endl;

    // range-based for loop
    for (int i : set1) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
