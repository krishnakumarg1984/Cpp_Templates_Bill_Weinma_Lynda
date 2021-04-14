// lambda.cpp by Bill Weinman <http://bw.org/>
// 2018-09-24 for CppSTL
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    auto x = [](string& s) -> size_t {
        return s.size();
    };  // This is a lambda function

    vector<string> v1 = {"one", "two", "three", "four", "five"};
    disp_v(v1);

    vector<size_t> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(),
              x);  // 'x' in this case is a lambda function

    disp_v(v2);

    return 0;
}
