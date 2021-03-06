// array.cpp by Bill Weinman <http://bw.org/>;
// 2019-11-04 for CppSTL
#include <array>
#include <iostream>
#include <string>
using namespace std;

// STL array-type is a fixed size sequence container. Is created when the
// array is defined & size cannot change for the life of the array
// C++11 onwards. Fast & efficient, but less functional than a vector.
// Elements are guaranteed to be in contiguous memory locations.
// Is a wrapper around the C-array

// print the elements of the array
template <typename T, size_t N>
void printa(array<T, N>& a) {
    for (T& i : a)
        cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char* s) {
    cout << s << endl;
}
template <typename T>
void message(const char* s, const T& v) {
    cout << s << ": " << v << endl;
}

int main() {
    // initializer list
    message("initializer list");
    array<int, 5> a1 = {1, 2, 3, 4, 5};
    printa(a1);

    // default constructor
    message("default constructor");
    array<string, 5> a2;
    a2 = {"one", "two", "three"};  // Size is 5, but only has 3 elements
    printa(a2);

    // check the size, but both size shall be 5, even though a2 has only 3
    // elements
    message("size of a1", (int)a1.size());
    message("size of a2", (int)a2.size());

    // access elements
    message("a1 element 3 is", a1[3]);
    message("a2 element 2 is", a2[2]);
    message("a1 element 3 is", a1.at(3));
    message("a2 element 2 is", a2.at(2));

    // direct access data. The data() function returns the underlying array
    int* ip1 = a1.data();
    for (size_t i = 0; i < a1.size(); ++i) {
        cout << "element " << i << " is " << *ip1++ << endl;
    }

    string* ip2 = a2.data();
    for (size_t i = 0; i < a2.size(); ++i) {
        cout << "element " << i << " is " << *ip2++ << endl;
    }

    return 0;
}
