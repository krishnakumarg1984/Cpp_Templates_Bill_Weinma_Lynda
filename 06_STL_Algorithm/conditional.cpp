// conditional.cpp by Bill Weinman <http://bw.org/>
// 2018-09-29 for CppSTL
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// A predicate function
// Here, a unary predicate
template <typename T>
const bool is_prime(const T& num) {
    if (num <= 1)
        return false;
    bool primeflag = true;
    for (T l = 2; l < num; ++l) {
        if (num % l == 0) {
            primeflag = false;
            break;
        }
    }
    return primeflag;
}

template <typename T>
void disp_v(const T& v) {
    if (!v.size())
        return;
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    // prime numbers < 100
    // const vector<int> v1 = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
    // 41,
    //                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    // const vector<int> v1 = {2,  40, 3,  5,  7,  11, 13, 17, 19, 23, 29, 31,
    // 37,
    //                         41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
    //                         97};
    // const vector<int> v1 = {1, 4, 6, 8, 10, 12, 14};
    // const vector<int> v1 = {1, 4, 6, 8, 10, 12, 14, 7};
    const vector<int> v1 = {1, 4, 6, 8, 10, 12, 14};
    disp_v(v1);

    // Tests all of the elements in a container against a predicate
    // if (all_of(v1.begin(), v1.end(), is_prime<int>)) {
    // if (any_of(v1.begin(), v1.end(), is_prime<int>)) {
    if (none_of(v1.begin(), v1.end(), is_prime<int>)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
