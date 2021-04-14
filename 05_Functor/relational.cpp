// relational.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <functional>  // relational functors are here
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

template <typename T>
void disp_v(vector<T>& v) {
    if (!v.size())
        return;
    if (typeid(T) == typeid(bool)) {
        for (bool e : v) {
            cout << (e ? "T" : "F") << " ";
        }
    } else {
        for (T e : v) {
            cout << e << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<long> v1 = {26, 52, 79, 114, 183};
    vector<long> v2 = {52, 2, 72, 114, 5};  // not sorted
    vector<bool> v3(v1.size());
    disp_v(v1);
    disp_v(v2);
    cout << endl;

    // greater<long> f;
    // less<long> f;
    // greater_equal<long> f;
    // less_equal<long> f;
    // equal_to<long> f;
    // not_equal_to<long> f;
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    // disp_v(v3);

    // greater<long> f;
    // sort(v2.begin(), v2.end(), f); // for descending sort order

    less<long> f;
    sort(v2.begin(), v2.end(), f);  // for descending sort order

    disp_v(v2);

    return 0;
}
