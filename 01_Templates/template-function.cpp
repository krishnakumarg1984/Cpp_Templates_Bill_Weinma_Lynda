// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
using namespace std;

// A template is a compiler abstraction that allows you to write generic code
// that applies to various types of classes without concern for the details of the type

// A template function
template <typename T>  // The abstraction is the type T
T maxof(const T & a, const T & b) {
    return ( a > b ? a : b );
}

// int maxof(const int & a, const int & b) {
//     return ( a > b ? a : b );
// }

int main() {
    // int a = 7;
    // int b = 9;
    // cout << "max is " << maxof(a, b) << endl;

    string a = "seven";
    string b = "nine";
    cout << "max is " << maxof<string>( a, b ) << endl;

    return 0;
}
