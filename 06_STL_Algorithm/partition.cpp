// partition.cpp by Bill Weinman <http://bw.org/>
// 2018-10-01 for CppSTL
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Rearrange a container so that elements that meet a criterion are at the
// beginning

template <typename T>
bool is_even_tens(T& n) {
    if (n < 10)
        return false;
    return ((n / 10) % 2) == 0;
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
    // prime numbers > 10 & < 100
    vector<int> v1 = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                      53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    disp_v(v1);

    // Within each partition, the elements are no longer in order
    // partition(v1.begin(), v1.end(), is_even_tens<int>);

    // Takes a bit more time & memory to perform this
    // stable_partition(v1.begin(), v1.end(), is_even_tens<int>);

    size_t sz = count_if(v1.begin(), v1.end(), is_even_tens<int>);
    std::vector<int> v2(sz), v3(v1.size() - sz);
    // v2: container for those that match the criterion
    // v3: container for those that do not match the criterion
    partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin(),
                   is_even_tens<int>);

    disp_v(v1);
    disp_v(v2);
    disp_v(v3);

    return 0;
}
