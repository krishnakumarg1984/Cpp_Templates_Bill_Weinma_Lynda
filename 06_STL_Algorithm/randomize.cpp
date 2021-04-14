// randomize.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <iostream>
#include <random>  // provides the mt algorithm
#include <vector>
using namespace std;

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
    vector<int> v1 = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    disp_v(v1);

    random_device rd;

    // mersenne twister algorithm
    mt19937 g(rd());

    // Does almost the same thing as random_shuffle, but requires an external
    // random number generator
    shuffle(v1.begin(), v1.end(), g);
    disp_v(v1);

    return 0;
}
