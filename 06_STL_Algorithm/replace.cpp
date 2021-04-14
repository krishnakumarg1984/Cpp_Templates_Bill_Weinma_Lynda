// replace.cpp by Bill Weinman <http://bw.org/>
// 2018-09-30 for CppSTL
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool is_even(const T& n) {
    return ((n % 2) == 0);
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
    // Not using const-safe functions because they do change the containers
    vector<int> v1 = {2,  3,  5,  7,  11, 11, 11, 11, 42, 47, 13,
                      17, 19, 47, 23, 31, 37, 47, 41, 48, 94, 46,
                      43, 59, 47, 61, 28, 30, 41, 86, 47, 47};
    disp_v(v1);

    // search for 47 & replace all occurrences with 99
    // replace(v1.begin(), v1.end(), 47, 99);

    // Remove 47 from the container
    // auto it = remove(v1.begin(), v1.end(), 47);

    // auto it = remove_if(v1.begin(), v1.end(), is_even<int>);

    // Removes consecutive duplicates from the container
    auto it = unique(v1.begin(), v1.end());

    if (it == v1.end()) {
        std::cout << "No elements were removed" << std::endl;
    } else {
        v1.resize(it - v1.begin());
    }

    // replace_if(v1.begin(), v1.end(), is_even<int>, 99);

    disp_v(v1);

    return 0;
}
