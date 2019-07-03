// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
// template <class T, class X>  // T & X are the template parameters
T maxof(const T & a, const T & b) {
    return ( a > b ? a : b );
}

int main() {

    int a = 7;
    int b = 9;
    cout << "max is " << maxof(a, b) << endl;

    vector<int> v1 = {1, 2, 3, 4, 5};

    return 0;
}
