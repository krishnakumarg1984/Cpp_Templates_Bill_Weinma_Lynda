// binary-transformation.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class embiggen {
    T _accum = 1;

   public:
    T operator()(const T& n1, const T& n2) {
        return _accum = n1 * n2 * _accum;
    }
};

template <typename T>
void disp_v(vector<T>& v) {
    if (!v.size())
        return;
    for (T e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    vector<long> v1 = {1, 2, 3, 4, 5};
    vector<long> v2 = {5, 10, 15, 20, 25};
    vector<long> v3(v1.size(), 0);
    // embiggen<long> fbig;
    multiplies<long> fbig;

    disp_v(v1);
    disp_v(v2);
    disp_v(v3);
    std::cout << endl;

    // 2 src & 1 desination for this binary transformation
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), fbig);
    transform(v1.begin(), v1.end(), v2.begin(), v1.begin(),
              fbig);  // destination can be one of the sources
    disp_v(v1);
    disp_v(v2);
    disp_v(v3);

    return 0;
}
