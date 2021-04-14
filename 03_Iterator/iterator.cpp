// iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <vector>
using namespace std;

// An iterator is an STL object that can iterate through the elements of a
// container An iterator acts a lot like a pointer

int main() {
    vector<int> vi1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector <int>::iterator it1;   // iterator object. Iterator class is
    // defined in the scope of the container class. Accessed through the scope
    // resolution operator :: . The type of the iterator is bound to the type of
    // the class. Won't work with any other class or templated class. Will only
    // work with a vector of ints.

    // vector <int>::iterator ibegin = vi1.begin();
    // vector <int>::iterator iend = vi1.end();

    auto ibegin = vi1.begin();
    auto iend = vi1.end();

    // for (it1 = ibegin; it1 < iend; ++it1) {
    for (auto it1 = ibegin; it1 < iend; ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    return 0;
}
