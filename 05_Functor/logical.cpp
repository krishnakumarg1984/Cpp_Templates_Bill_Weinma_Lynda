// logical.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void disp_v(T& v) {
    if (!v.size())
        return;
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    // can be any logical compatible type (here, ints). Can be 'bool' for eg
    // vector<int> v1 = {1, 0, 1, 0, 1, 0, 1, 0};
    // vector<int> v2 = {1, 1, 1, 1, 0, 0, 0, 0};
    // vector<int> v3(v1.size(), 0);
    vector<bool> v1 = {1, 0, 1, 0, 1, 0, 1, 0};
    vector<bool> v2 = {1, 1, 1, 1, 0, 0, 0, 0};
    vector<bool> v3(v1.size(), 0);
    disp_v(v1);
    disp_v(v2);
    cout << endl;

    // logical_and<int> f;
    // logical_and<bool> f;
    // logical_or<bool> f;
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);

    logical_not<bool> f;  // is a unary function
    transform(v1.begin(), v1.end(), v3.begin(), f);
    disp_v(v3);

    return 0;
}
