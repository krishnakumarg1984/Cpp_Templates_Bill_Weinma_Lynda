// forward-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <forward_list>  // single linked list type. Efficient in iterating from beginning to end, but not the other way around
#include <iostream>
using namespace std;

// More flexible than input or output iterators, since it can both read &
// write, but still lacks direct access.

int main() {
    forward_list<int> fl1 = {1, 2, 3, 4, 5};
    forward_list<int>::iterator it1;  // forward iterator

    // it1 = fl1.end();
    // --it1;

    // for (it1 = fl1.begin(); it1!= fl1.end(); ++it1) {
    //     cout << *it1 << " ";
    // }

    // Because the range-based for loop uses an iterator
    for (int i : fl1) {
        std::cout << i << " ";
    }

    cout << endl;

    return 0;
}
